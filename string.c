#include <stdio.h>
#include <string.h>

int main ( ) {
  char input[80], rotate[80];
  int  len, i;
  printf( "Enter word\n" );
  scanf( "%s", input );

  strcpy( rotate, input );
  strcat( rotate, input );
  len = strlen ( input );
  for ( i = 0 ; i < len ; i++ ) {
    printf( "%.*s\n", len, &rotate[i] );
  }
  return 0;
}
