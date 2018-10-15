#ifndef OSMIUM_OSM_TYPES_HPP
#define OSMIUM_OSM_TYPES_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013-2017 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <cstdint>

namespace osmium {

    /*
     * The following types are chosen so that they can represent all needed
     * numbers and still be reasonably space efficient. As the OSM database
     * needs 64 bit IDs for nodes, this size is used for all object IDs.
     */
    using object_id_type          =  int64_t; ///< Type for OSM object (node, way, or relation) IDs.
    using unsigned_object_id_type = uint64_t; ///< Type for OSM object (node, way, or relation) IDs where we only allow positive IDs.
    using object_version_type     = uint32_t; ///< Type for OSM object version number.
    using changeset_id_type       = uint32_t; ///< Type for OSM changeset IDs.
    using user_id_type            = uint32_t; ///< Type for OSM user IDs.
    using signed_user_id_type     =  int32_t; ///< Type for signed OSM user IDs.
    using num_changes_type        = uint32_t; ///< Type for changeset num_changes.
    using num_comments_type       = uint32_t; ///< Type for changeset num_comments.

    /**
     * Size for strings in OSM data such as user names, tag keys, roles, etc.
     * In Osmium they can be up to 2^16 bytes long, but OSM usually has lower
     * defined limits.
     */
    using string_size_type = uint16_t;

    // maximum of 256 characters of max 4 bytes each (in UTF-8 encoding)
    constexpr const int max_osm_string_length = 256 * 4;

} // namespace osmium

#endif // OSMIUM_OSM_TYPES_HPP