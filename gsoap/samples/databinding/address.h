/* ./address.h
   Generated by wsdl2h 2.8.11 from ./address.xsd and ./addresstypemap.dat
   2012-10-13 21:01:26 GMT

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS
   USE THE soapcpp2-GENERATED SOURCE CODE FILES FOR YOUR PROJECT BUILDS

   gSOAP XML Web services tools.
   Copyright (C) 2001-2012 Robert van Engelen, Genivia Inc. All Rights Reserved.
   Part of this software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/** @page page_notes Usage Notes

NOTE:

 - Run soapcpp2 on ./address.h to generate the SOAP/XML processing logic.
   Use soapcpp2 option -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
   Use soapcpp2 option -i to generate improved proxy and server classes.
 - Use wsdl2h options -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) on this file to generate documentation.
 - Use wsdl2h options -nname and -Nname to globally rename the prefix 'ns'.
 - Use wsdl2h option -d to enable DOM support for xsd:anyType.
 - Use wsdl2h option -g to auto-generate readers and writers for root elements.
 - Struct/class members serialized as XML attributes are annotated with a '@'.
 - Struct/class members that have a special role are annotated with a '$'.

WARNING:

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS.
   USE THE SOURCE CODE FILES GENERATED BY soapcpp2 FOR YOUR PROJECT BUILDS:
   THE soapStub.h FILE CONTAINS THIS CONTENT WITHOUT ANNOTATIONS.

LICENSE:

@verbatim
--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.

This software is released under one of the following two licenses:
1) GPL or 2) Genivia's license for commercial use.
--------------------------------------------------------------------------------
1) GPL license.

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
2) A commercial-use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
@endverbatim

*/


//gsoapopt w

/******************************************************************************\
 *                                                                            *
 * Definitions                                                                *
 *   urn:address-book-example                                                 *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


// STL vector containers (use option -s to remove STL dependency)
#import "stlvector.h"

/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

a = "urn:address-book-example"

*/

/// @brief An example address book schema
#define SOAP_NAMESPACE_OF_a	"urn:address-book-example"
//gsoap a     schema namespace:	urn:address-book-example
//gsoap a     schema form:	unqualified

/******************************************************************************\
 *                                                                            *
 * Built-in Schema Types and Top-Level Elements and Attributes                *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Forward Declarations                                                       *
 *                                                                            *
\******************************************************************************/



//  Forward declaration of class a__address.
class a__address;

//  Forward declaration of class _a__address_book.
class _a__address_book;

/******************************************************************************\
 *                                                                            *
 * Schema Types and Top-Level Elements and Attributes                         *
 *   urn:address-book-example                                                 *
 *                                                                            *
\******************************************************************************/


/// "urn:address-book-example":ISO-country is a simpleType restriction of xs:string.
/// @brief ISO country codes (limited to just a few for this example)
/// Note: enum values are prefixed with 'a__ISO_country' to avoid name clashes, please use wsdl2h option -e to omit this prefix
enum a__ISO_country
{
	a__ISO_country__be,	///< xs:string value="be"
	a__ISO_country__ca,	///< xs:string value="ca"
	a__ISO_country__de,	///< xs:string value="de"
	a__ISO_country__en,	///< xs:string value="en"
	a__ISO_country__gb,	///< xs:string value="gb"
	a__ISO_country__it,	///< xs:string value="it"
	a__ISO_country__nl,	///< xs:string value="nl"
	a__ISO_country__no,	///< xs:string value="no"
	a__ISO_country__ru,	///< xs:string value="ru"
	a__ISO_country__se,	///< xs:string value="se"
	a__ISO_country__us,	///< xs:string value="us"
};

/******************************************************************************\
 *                                                                            *
 * Schema Complex Types and Top-Level Elements                                *
 *   urn:address-book-example                                                 *
 *                                                                            *
\******************************************************************************/


/// "urn:address-book-example":address is a complexType.
/// @brief An address information item
class a__address
{ public:
/// Element name of type xs:string.
    std::string                          name                           1;	///< Required element.
/// Element street of type xs:string.
    std::string                          street                         1;	///< Required element.
/// Element city of type xs:string.
    std::string                          city                           1;	///< Required element.
/// Element zip of type xs:string.
    std::string                          zip                            1;	///< Required element.
/// Element country of type "":ISO-country.
    enum a__ISO_country                  country                        0 = a__ISO_country__us;	///< Default value="us".
/// Element phone of type xs:string.
    std::string*                         phone                          0;	///< Nullable pointer.
/// Element mobile of type xs:string.
    std::string*                         mobile                         0;	///< Nullable pointer.
/// Element dob of type xs:dateTime.
    time_t*                              dob                            0;	///< Nullable pointer.
/// Attribute ID of type xs:int.
   @int                                  ID                             1;	///< Required attribute.
/// A handle to the soap struct that manages this instance (automatically set)
    struct soap                         *soap                          ;
};


/// Top-level root element "urn:address-book-example":address-book
/// @brief The root element of the address book schema

/// "urn:address-book-example":address-book is a complexType.
class _a__address_book
{ public:
/// Vector of a__address* with length 0..unbounded
    std::vector<a__address*            > address                        0;
/// A handle to the soap struct that manages this instance (automatically set)
    struct soap                         *soap                          ;
};

/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Elements                                              *
 *   urn:address-book-example                                                 *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Additional Top-Level Attributes                                            *
 *   urn:address-book-example                                                 *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * XML Data Binding                                                           *
 *                                                                            *
\******************************************************************************/


/**

@page page_XMLDataBinding XML Data Binding

SOAP/XML services use data bindings contractually bound by WSDL and auto-
generated by wsdl2h and soapcpp2 (see Service Bindings). Plain data bindings
are adopted from XML schemas as part of the WSDL types section or when running
wsdl2h on a set of schemas to produce non-SOAP-based XML data bindings.

The following readers and writers are C/C++ data type (de)serializers auto-
generated by wsdl2h and soapcpp2. Run soapcpp2 on this file to generate the
(de)serialization code, which is stored in soapC.c[pp]. Include "soapH.h" in
your code to import these data type and function declarations. Only use the
soapcpp2-generated files in your project build. Do not include the wsdl2h-
generated .h file in your code.

XML content can be retrieved from:
  - a file descriptor, using soap->recvfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->is = ...
  - a buffer, using the soap->frecv() callback

XML content can be stored to:
  - a file descriptor, using soap->sendfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->os = ...
  - a buffer, using the soap->fsend() callback


@section a Top-level root elements of schema "urn:address-book-example"

  - <a:address-book> @ref _a__address_book
    @code
    // Reader (returns SOAP_OK on success):
    soap_read__a__address_book(struct soap*, _a__address_book*);
    // Writer (returns SOAP_OK on success):
    soap_write__a__address_book(struct soap*, _a__address_book*);
    @endcode

*/

/* End of ./address.h */
