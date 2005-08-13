#ifndef foointernalhfoo
#define foointernalhfoo

/* $Id$ */

/***
  This file is part of avahi.
 
  avahi is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.
 
  avahi is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General
  Public License for more details.
 
  You should have received a copy of the GNU Lesser General Public
  License along with avahi; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <dbus/dbus.h>

struct _AvahiClient
{
    DBusConnection *bus;
    int error;
    AvahiClientCallback callback;
    void *user_data;
    AVAHI_LLIST_HEAD(AvahiClientEntryGroup, groups);
    AVAHI_LLIST_HEAD(AvahiClientDomainBrowser, domain_browsers);
    AVAHI_LLIST_HEAD(AvahiClientServiceTypeBrowser, service_type_browsers);
};

struct _AvahiClientEntryGroup {
    char *path;
    AvahiClient *client;
    AvahiClientEntryGroupCallback callback;
    void *user_data;
    AVAHI_LLIST_FIELDS(AvahiClientEntryGroup, groups);
};

struct _AvahiClientDomainBrowser {
    char *path;
    AvahiClient *client;
    AvahiClientDomainBrowserCallback callback;
    void *user_data;
    AVAHI_LLIST_FIELDS(AvahiClientDomainBrowser, domain_browsers);
};

struct _AvahiClientServiceTypeBrowser {
    char *path;
    AvahiClient *client;
    AvahiClientServiceTypeBrowserCallback callback;
    void *user_data;
    AVAHI_LLIST_FIELDS(AvahiClientServiceTypeBrowser, service_type_browsers);
};

int avahi_client_set_errno (AvahiClient *client, int error);

void avahi_entry_group_state_change (AvahiClientEntryGroup *group, int state);

DBusHandlerResult avahi_domain_browser_event (AvahiClient *client, AvahiBrowserEvent event, DBusMessage *message);

DBusHandlerResult avahi_service_type_browser_event (AvahiClient *client, AvahiBrowserEvent event, DBusMessage *message);

#endif