/*
	int128.c

	Custom serializer for __int128_t_t as xsd:integer (big int).

	Compile this file and link it with your code.

gSOAP XML Web services tools
Copyright (C) 2000-2015, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, the gSOAP public license, OR Genivia's license for commercial use.
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2015, Robert van Engelen, Genivia, Inc., All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

/* soapH.h generated by soapcpp2 from .h file containing #import "int128.h" */
#include "soapH.h"

void soap_default_xsd__integer(struct soap *soap, __int128_t *a)
{
  (void)soap;
  *a = 0;
}

void soap_serialize_xsd__integer(struct soap *soap, const __int128_t *a)
{
  (void)soap; (void)a;
}

int soap_s2xsd__integer(struct soap *soap, const char *s, __int128_t *a)
{
  if (s)
  {
    if (!*s)
      return soap->error = SOAP_TYPE;
    else
    {
      __int128_t bigint = 0;
      /* INT128_MIN = -170141183460469231731687303715884105728 */
      __int128_t min128 = -(((__int128_t)UINT64_MAX + 1) * 0x7FFFFFFFFFFFFFFFULL + 0xFFFFFFFFFFFFFFFFULL) - 1;
      /* INT128_MAX/10 = 17014118346046923173168730371588410572 */
      __int128_t max128over10 = ((__int128_t)UINT64_MAX + 1) * 0x0CCCCCCCCCCCCCCCULL + 0xCCCCCCCCCCCCCCCCULL;
      short len = 0, neg = 0;
      if (*s == '-')
      {
	neg = 1;
	s++;
      }
      else if (*s == '+')
	s++;
      while (isdigit(*s) && (len++ < 38 || bigint < max128over10 || (bigint == max128over10 && *s <= '7')))
	bigint = 10*bigint + (*s++ - '0');
      if (neg && len == 39 && bigint == max128over10 && *s == '8' && !*++s)
	*a = min128;
      else if (*s)
        soap->error = SOAP_TYPE;
      else if (neg)
	*a = -bigint;
      else
	*a = bigint;
    }
  }
  return soap->error;
}

const char * soap_xsd__integer2s(struct soap *soap, __int128_t a)
{
  char *s = soap->tmpbuf;
  /* INT128_MIN = -170141183460469231731687303715884105728 */
  __int128_t min128 = -(((__int128_t)UINT64_MAX + 1) * 0x7FFFFFFFFFFFFFFFULL + 0xFFFFFFFFFFFFFFFFULL) - 1;
  if (a < 0)
  {
    if (a == min128)
      return "-170141183460469231731687303715884105728";
    *s++ = '-';
    a = -a;
  }
  if (a > UINT64_MAX)
  {
    __int128_t l = a / 10000000000000000000ULL; /* leading digits */
    uint64_t   t = a % 10000000000000000000ULL; /* trailing 19 digits */
    if (l > UINT64_MAX)
    {
      uint64_t ll = l / 10000000000000000000ULL;
      uint64_t tl = l % 10000000000000000000ULL;
      (SOAP_SNPRINTF(s, (s - soap->tmpbuf) + sizeof(soap->tmpbuf), 20), "%" PRIu64, ll);
      s += strlen(s);
      (SOAP_SNPRINTF(s, (s - soap->tmpbuf) + sizeof(soap->tmpbuf), 20), "%0.19" PRIu64, tl);
    }
    else
    {
      (SOAP_SNPRINTF(s, (s - soap->tmpbuf) + sizeof(soap->tmpbuf), 20), "%" PRIu64, (uint64_t)l);
    }
    s += strlen(s);
    (SOAP_SNPRINTF(s, (s - soap->tmpbuf) + sizeof(soap->tmpbuf), 20), "%0.19" PRIu64, t);
  }
  else
  {
    (SOAP_SNPRINTF(s, sizeof(soap->tmpbuf) - 1, 20), "%" PRIu64, (uint64_t)a);
  }
  return soap->tmpbuf;
}

int soap_out_xsd__integer(struct soap *soap, const char *tag, int id, const __int128_t *p, const char *type)
{
  if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, p, SOAP_TYPE_xsd__integer), type)
   || soap_string_out(soap, soap_xsd__integer2s(soap, *p), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}

__int128_t * soap_in_xsd__integer(struct soap *soap, const char *tag, __int128_t *a, const char *type)
{
  if (soap_element_begin_in(soap, tag, 0, type))
    return NULL;
  a = (__int128_t*)soap_id_enter(soap, soap->id, a, SOAP_TYPE_xsd__integer, sizeof(__int128_t), NULL, NULL, NULL, NULL);
  if (*soap->href)
    a = (__int128_t*)soap_id_forward(soap, soap->href, a, 0, SOAP_TYPE_xsd__integer, 0, sizeof(__int128_t), 0, NULL, NULL);
  else if (a)
  {
    if (soap_s2xsd__integer(soap, soap_value(soap), a))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return a;
}
