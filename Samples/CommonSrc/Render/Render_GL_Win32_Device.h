/************************************************************************************

Filename    :   Render_GL_Win32 Device.h
Content     :   Win32 OpenGL Device implementation header
Created     :   September 10, 2012
Authors     :   Andrew Reisse, Michael Antonov

Copyright   :   Copyright 2012 Oculus VR, Inc. All Rights reserved.

Use of this software is subject to the terms of the Oculus LLC license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

************************************************************************************/

#ifndef OVR_Render_GL_Win32_Device_h
#define OVR_Render_GL_Win32_Device_h

#include "Render_GL_Device.h"

#ifdef WIN32
#include <Windows.h>
#endif


namespace OVR { namespace Render { namespace GL { namespace Win32 {

// ***** GL::Win32::RenderDevice

// Win32-Specific GL Render Device, used to create OpenGL under Windows.
class RenderDevice : public GL::RenderDevice
{
    HWND   Window;
    HGLRC  WglContext;
    HDC    GdiDc;

public:
    RenderDevice(const Render::RendererParams& p, HWND win, HDC dc, HGLRC gl)
        : GL::RenderDevice(p), Window(win), WglContext(gl), GdiDc(dc) { OVR_UNUSED(p); }

    // Implement static initializer function to create this class.
    static Render::RenderDevice* CreateDevice(const RendererParams& rp, void* oswnd);

    virtual void Shutdown();
    virtual void Present();
};


}}}} // OVR::Render::GL::Win32

#endif
