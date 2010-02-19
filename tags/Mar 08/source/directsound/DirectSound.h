/*
* Copyright (c) 2007-2008 SlimDX Group
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
#pragma once

#include "../ComObject.h"

#include "Enums.h"

using System::Runtime::InteropServices::OutAttribute;

namespace SlimDX
{
	namespace DirectSound
	{
		[System::Runtime::InteropServices::StructLayout( System::Runtime::InteropServices::LayoutKind::Sequential, Pack = 4 )]
		public value class Capabilities
		{
			int Size;
			int Flags;
			int MinSecondarySampleRate;
			int MaxSecondarySampleRate;
			int PrimaryBuffers;
			int MaxHwMixingAllBuffers;
			int MaxHwMixingStaticBuffers;
			int MaxHwMixingStreamingBuffers;
			int FreeHwMixingAllBuffers;
			int FreeHwMixingStaticBuffers;
			int FreeHwMixingStreamingBuffers;
			int MaxHw3DAllBuffers;
			int MaxHw3DStaticBuffers;
			int MaxHw3DStreamingBuffers;
			int FreeHw3DAllBuffers;
			int FreeHw3DStaticBuffers;
			int FreeHw3DStreamingBuffers;
			int TotalHwMemoryBytes;
			int FreeHwMemoryBytes;
			int MaxContigFreeHwMemoryBytes;
			int UnlockTransferRateHwBuffers;
			int PlayCpuOverheadSwBuffers;
			int Reserved1;
			int Reserved2;
		};

		public ref class DirectSound : ComObject
		{
			COMOBJECT(IDirectSound8, DirectSound);

		private:
			Capabilities caps;
			Capabilities GetCapabilities();

		public:
			DirectSound();
			DirectSound( System::Guid device );
			static DirectSound^ FromPointer( System::IntPtr pointer );

			void Initialize();
			void Initialize( System::Guid device );

			void SetCooperativeLevel( System::IntPtr windowHandle, CooperativeLevel coopLevel );
			void SetSpeakerConfig( Speaker speakerSet, SpeakerGeometry geometry );
			void GetSpeakerConfig( [Out] Speaker% speakerSet, [Out] SpeakerGeometry% geometry );
			bool VerifyCertification();

			property Capabilities Capabilities
			{
				SlimDX::DirectSound::Capabilities get() { return caps; }
			}
		};
	}
}