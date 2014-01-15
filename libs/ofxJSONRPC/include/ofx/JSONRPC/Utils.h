// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <string>
#include <json/json.h>
#include "ofx/JSONRPC/Errors.h"
#include "ofx/JSONRPC/Response.h"
#include "ofx/JSONRPC/Request.h"


namespace ofx {
namespace JSONRPC {


class Utils
    /// \brief A collection of utilities for JSONRPC.
{
public:
    static std::string toString(const Json::Value& json, bool styled = false);
        ///< \brief Convert JSON values to a raw string representation.
        ///< \param json The JSON value to convert.
        ///< \param styled if true, the raw string will be indented
        ///<        with returns and thus easier to read.
        ///< \returns A raw string representation of the JSON.

    static std::string toString(const Response& response, bool styled = false);
    static std::string toString(const Request& request, bool styled = false);

};


} } // namespace ofx::JSONRPC