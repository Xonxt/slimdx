/*
* Copyright (c) 2007-2009 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifdef WRAP_XAPO

#include <windows.h>
#include <audiodefs.h>

#include "../WaveFormat.h"

#include "LockParameter.h"

namespace SlimDX
{
namespace XAPO
{
	bool LockParameter::operator == ( LockParameter left, LockParameter right )
	{
		return LockParameter::Equals( left, right );
	}

	bool LockParameter::operator != ( LockParameter left, LockParameter right )
	{
		return !LockParameter::Equals( left, right );
	}

	int LockParameter::GetHashCode()
	{
		return Format->GetHashCode() + MaxFrameCount.GetHashCode();;
	}

	bool LockParameter::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<LockParameter>( value ) );
	}

	bool LockParameter::Equals( LockParameter value )
	{
		return ( Format == value.Format && MaxFrameCount == value.MaxFrameCount );
	}

	bool LockParameter::Equals( LockParameter% value1, LockParameter% value2 )
	{
		return ( value1.Format == value2.Format && value1.MaxFrameCount == value2.MaxFrameCount );
	}
}
}

#endif