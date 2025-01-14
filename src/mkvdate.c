/* $Id: mkvdate.c,v 1.5 2001/12/26 22:17:03 sybalsky Exp $ (C) Copyright Venue, All Rights Reserved
 */

/************************************************************************/
/*									*/
/*	(C) Copyright 1989-95 Venue. All Rights Reserved.		*/
/*	Manufactured in the United States of America.			*/
/*									*/
/************************************************************************/

#include "version.h"

/************************************************************************/
/*									*/
/*			m a k e v d a t e . c 				*/
/*									*/
/*	Make the version number to place in the emulator.  That number	*/
/*	will be smashed into the running sysout at the field		*/
/*	InterfacePage->rversion.  The version number is the number	*/
/*	of whole days since 12:00 13-Oct-87 (Takeshi's birthday).	*/
/*									*/
/*	This program prints a single line:				*/
/*		long MDate = <the version number>			*/
/*									*/
/*	That output is redirected to create the file vdate.c, which	*/
/*	is then compiled as part of the emulator MAKE.			*/
/*									*/
/************************************************************************/

#include <stdio.h>
#include <time.h>

#ifndef DOS
#include <sys/time.h>
#endif /* DOS */

#ifdef DOS
/* RISCOS doesn't have the BSD time functions */
int main(void) {
  long dtime;
  time(&dtime);
  fprintf(stderr, "Mdate :%ld\n", dtime);
  printf("long MDate= %ld;\n", dtime);
  return (0);
}
#else
/* Version for every other Unix */
int main(void) {
  struct timeval time;

  gettimeofday(&time, NULL);
  fprintf(stderr, "Mdate :%ld\n", (long)time.tv_sec);
  fprintf(stderr, "Version: %s\n", ctime(&time.tv_sec));

  printf("long MDate= %ld;\n", (long)time.tv_sec);
  return (0);
}

#endif /* DOS */
