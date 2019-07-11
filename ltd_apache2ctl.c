/*
A tiny utility to let non-super users restart apache2 on Linux. 
The makefile sets suid permission magic that makes this work.
Copyright 2015 Josiah Johnston. All rights reserved.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define MAX_ARG_LEN 16

int main(int argc, char *argv[]) {
  int red5_return_val; 
  if( argc > 1 ) {
    if( strncmp( argv[1], "restart", MAX_ARG_LEN ) == 0 ) {
      if( red5_return_val == 0 ) {
        red5_return_val = system( "/etc/init.d/red5 stop" );
        red5_return_val = system( "/etc/init.d/red5 start" );
        if( red5_return_val == 0 ) printf("Restart successful\n");
        else printf("Restart was problematic. Contact Cory. Please check error messages, fix the problem and try again.\n");
        return red5_return_val;
      } else {
        printf("\n\nThe configuration files have an error. Refusing to restart red5 until the errors are corrected.\n\n");      
      }
      return red5_return_val;
    }
  }

  printf( "Usage: %s restart\n", argv[0]);
  return 0;
}
