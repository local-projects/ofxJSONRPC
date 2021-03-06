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
#include <map>
#include "json/json.h"
#include "ofx/JSONRPC/Errors.h"


namespace ofx {
namespace JSONRPC {


/// \brief A JSONRPC 2.0 error object.
/// \sa http://www.jsonrpc.org/specification
class Error
{
public:
    /// \brief Create an Error.
    /// \note The code will be set to Errors::RPC_ERROR_NONE.
    Error();

    /// \brief Create an Error.
    /// \param code is the error code.
    /// \note The error message will be queried based on the code.
    /// \note The data field will be left blank.
    explicit Error(int code);

	/// \brief Create an Error.
	/// \param code is the error code.
	/// \param message the error message.
	explicit Error(int code, const Json::Value& data);

	/// \brief Create an Error.
	/// \param code is the error code.
	/// \param message the error message.
	/// \param data the error data.
	explicit Error(int code, const std::string& message, const Json::Value& data);

    /// \brief Destroy the Error.
    virtual ~Error();

    /// \returns the error code.
    int getCode() const;

    /// \returns the error message.
    std::string getMessage() const;

    /// \returns the data.
    /// \note The JSON data may be empty.
    Json::Value getData() const;

    /// \brief Serialize the Error object to JSON.
    /// \param error the Error object to serialize.
    /// \returns JSONRPC compatible JSON.
    static Json::Value toJSON(const Error& error);

    /// \brief Deserialize the JSON to a Error object.
    /// \param json JSONRPC compatible JSON to deserialize.
    /// \returns the deserialized Error.
    /// \throws Poco::Exception if the JSON is not valid.
    static Error fromJSON(const Json::Value& json);

protected:
    /// \brief A Number that indicates the error type that occurred.
    /// \details This code MUST be an integer.
    int _code;

    /// \brief A String providing a short description of the error.
    /// \details The message SHOULD be limited to a concise single sentence.
    std::string _message;

    /// \brief A Json::Value that contains additional error info.
    ///
    /// This may be omitted. The value of this member is defined by the Server
    /// (e.g. detailed error information, nested errors etc.).
    Json::Value _data;

    /// \brief Error code tag.
    static const std::string ERROR_CODE_TAG;

    /// \brief Error message tag.
    static const std::string ERROR_MESSAGE_TAG;

    /// \brief Error data tag.
    static const std::string ERROR_DATA_TAG;

};


} } // namespace ofx::JSONRPC
