/*
* Copyright (c) 2007-2010 SlimDX Group
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
#include "stdafx.h"

#include "XACT3Exception.h"
#include "Engine.h"

#include "Cue.h"

namespace SlimDX
{
namespace XACT3
{
	void Cue::Play()
	{
		HRESULT hr = InternalPointer->Play();
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);
	}

	void Cue::Stop(StopFlags flags)
	{
		HRESULT hr = InternalPointer->Stop((DWORD)flags);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);
	}

	CueState Cue::State::get()
	{
		DWORD result;

		HRESULT hr = InternalPointer->GetState(&result);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);

		return (CueState)result;
	}

	void Cue::SetMatrixCoefficients(int srcChannelCount, int dstChannelCount, array<float>^ matrixCoefficients)
	{
		pin_ptr<float> pinnedMatrix = &matrixCoefficients[0];

		HRESULT hr = InternalPointer->SetMatrixCoefficients(srcChannelCount, dstChannelCount, pinnedMatrix);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);
	}

	int Cue::GetVariableIndex(String^ friendlyName)
	{
		XACTVARIABLEINDEX result;

		array<unsigned char>^ friendlyNameBytes = System::Text::ASCIIEncoding::ASCII->GetBytes(friendlyName);
		pin_ptr<unsigned char> pinnedFriendlyName = &friendlyNameBytes[0];
		result = InternalPointer->GetVariableIndex(reinterpret_cast<PCSTR>(pinnedFriendlyName));

		return result == XACTVARIABLEINDEX_INVALID ? -1 : result;
	}

	void Cue::SetVariable(int index, float value)
	{
		HRESULT hr = InternalPointer->SetVariable((XACTVARIABLEINDEX)index, (XACTVARIABLEVALUE)value);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);
	}

	float Cue::GetVariable(int index)
	{
		XACTVARIABLEVALUE value;

		HRESULT hr = InternalPointer->GetVariable((XACTVARIABLEINDEX)index, &value);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);

		return value;
	}

	void Cue::Pause(bool pause)
	{
		HRESULT hr = InternalPointer->Pause(pause);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);
	}

	CueInstanceProperties^ Cue::Properties::get()
	{
		LPXACT_CUE_INSTANCE_PROPERTIES resultPointer = NULL;

		HRESULT hr = InternalPointer->GetProperties(&resultPointer);
		if (RECORD_XACT3(hr).IsFailure)
			throw gcnew XACT3Exception(Result::Last);

		CueInstanceProperties^ result = gcnew CueInstanceProperties(*resultPointer);
		CoTaskMemFree(resultPointer);

		return result;
	}
}
}
