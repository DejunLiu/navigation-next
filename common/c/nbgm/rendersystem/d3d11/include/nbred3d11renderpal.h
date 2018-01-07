/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!--------------------------------------------------------------------------

@file nbred3d11renderpal.h
*/
/*
(C) Copyright 2012 by Networks In Motion, Inc.

The information contained herein is confidential, proprietary
to Networks In Motion, Inc., and considered a trade secret as
defined in section 499C of the penal code of the State of
California. Use of this information by anyone other than
authorized employees of Networks In Motion is granted only
under a written non-disclosure agreement, expressly
prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/
#ifndef _NBRE_D3D11_RENDERPAL_H_
#define _NBRE_D3D11_RENDERPAL_H_
#include "nbretypes.h"
#include "nbrerenderpal.h"
#include <d3d11.h>

class NBRE_D3D11RenderWindow;
class NBRE_D3D11FixedFuncSimulator;
class NBRE_D3D11GPUPorgramFactory;

/*! \addtogroup NBRE_RenderPal
*  @{
*/
/*! \addtogroup NBRE_D3D11RenderPal
*  @{
*/

struct NBRE_D3D11RenderEnv
{
    ID3D11Device* mD3D11Device;
    ID3D11DeviceContext* mImmediateContext;
    ID3D11DepthStencilView* mDepthStecilView;
    ID3D11RenderTargetView* mRenderTargetView;
    NBRE_String mWorkPath;
    PAL_Instance *mPal;
};

/** Implementation of Direct3D 11 as a rendering system. */
class NBRE_D3D11RenderPal: public NBRE_IRenderPal
{
public:
    NBRE_D3D11RenderPal(const NBRE_D3D11RenderEnv &env);
    ~NBRE_D3D11RenderPal();

public:
    //From NBRE_IRenderPal
    virtual nb_boolean BeginScene();
    virtual void EndScene();

    virtual void SetMaterial(const NBRE_Material& material);
    virtual void SetVertexBuffer(NBRE_VertexData* vtx);
    virtual void DrawIndexedPrimitive( NBRE_PrimitiveType type, const NBRE_IndexData* index );

    /// Create a render texture, immediate mode,
    virtual NBRE_Texture* CreateTexture(const NBRE_ImageInfo& info, NBRE_Texture::TextureType texType, nb_boolean isUsingMipmap, const NBRE_String& name);
    /// Create a general texture directly through images, immediate mode
    virtual NBRE_Texture* CreateTexture(NBRE_Image** image, uint8 faceCount, uint8 numMipmaps, nb_boolean isUsingMipmap, NBRE_Texture::TextureType texType, const NBRE_String& name);
    /// Create a general texture through a texture image, delay mode
    virtual NBRE_Texture* CreateTexture(NBRE_ITextureImage* textureImage, NBRE_Texture::TextureType texType, nb_boolean isUsingMipmap, const NBRE_String& name);
    virtual NBRE_RenderTarget* CreateRenderTargetFromTexture( NBRE_Texture* texture, int32 face );
    virtual NBRE_HardwareIndexBuffer* CreateIndexBuffer( NBRE_HardwareIndexBuffer::IndexType idxType, uint32 numIndexes, nb_boolean useShadowBuffer, NBRE_HardwareBuffer::Usage usage);
    virtual NBRE_HardwareVertexBuffer* CreateVertexBuffer( uint32 vertexSize, uint32 numVertices, nb_boolean useShadowBuffer ,NBRE_HardwareBuffer::Usage usage);
    virtual NBRE_VertexDeclaration* CreateVertexDeclaration(void);
    virtual NBRE_RenderTarget* GetDefaultRenderTarget();
    virtual void SelectRenderTarget( NBRE_RenderTarget* surface );
    virtual void SetViewPort( int32 left, int32 top, uint32 width , uint32 height );
    virtual void SetProjectionTransform( const NBRE_Matrix4x4f& mtrx );
    virtual void SetViewTransform( const NBRE_Matrix4x4d& mtrx );
    virtual void SetWorldTransform( const NBRE_Matrix4x4d& mtrx );
    virtual void SetDepthFunc(NBRE_CompareFunction f);
    virtual void SetAlphaFunc(NBRE_CompareFunction f, float refValue);
    virtual void SetFog(NBRE_FogMode mode, float density, float fogStart, float fogEnd, float red, float green, float blue, float alpha);
    virtual void EnableTexture( uint32 stage, nb_boolean bEnable );
    virtual void SelectTexture(uint32 stage, NBRE_Texture* texture);
    virtual void DisableTextureUnitsFrom( uint32 stage );
    virtual void SetTextureState(uint32 stage, const NBRE_TextureState& state);
    virtual void SetTextureTransform( uint32 stage, const NBRE_Matrix4x4f& mtrx );
    virtual void SetBlendFunc(NBRE_BlendFunction srcFactor, NBRE_BlendFunction dstFactor);
    virtual void SetClearColor(float r, float g, float b, float a);
    virtual void SetClearDepth(float value);
    virtual void SetClearStencil(int32 value);
    virtual void Clear(uint32 flags);
    virtual void SetColor(float r, float g, float b, float a);
    virtual void UseLights( const NBRE_LightList& light );
    virtual void SetActiveLights( const NBRE_LightIndexList& indices );
    virtual void EnableLighting( nb_boolean bEnable );
    virtual void EnableBlend( nb_boolean bEnable );
    virtual void EnableDepthTest( nb_boolean bEnable );
    virtual void EnableAlphaTest( nb_boolean bEnable );
    virtual void EnableStencilTest( nb_boolean bEnable );
    virtual void EnableColorWrite( nb_boolean enableRed, nb_boolean enableGreen, nb_boolean enableBlue, nb_boolean enableAlpha );
    virtual void EnableDepthWrite( nb_boolean bEnable );
    virtual void EnableStencilWrite( uint32 maskBits );
    virtual void EnableCullFace( nb_boolean bEnable );
    virtual void EnableFog( nb_boolean bEnable );
    virtual NBRE_GpuProgram* LoadGpuProgram( const char* vertShaderSrc, const char* fragShaderSrc );
    virtual const NBRE_RenderPalCapabilities& GetCapabilities() const { return mCapabilities; }
    virtual void SetTextureCoordSet(uint32 stage, uint32 index);
    ID3D11Device* GetActiveD3D11Device()       { nbre_assert(mEnv.mD3D11Device); return mEnv.mD3D11Device; }
    ID3D11DeviceContext* GetImmediateContext() { nbre_assert(mEnv.mImmediateContext); return mEnv.mImmediateContext; }
    NBRE_D3D11RenderEnv* GetD3D11RenderEnv() { return &mEnv; }
    virtual void SetWireframeMode(nb_boolean bLine);
    void ChangeD3D11View(ID3D11RenderTargetView* targetView, ID3D11DepthStencilView *depthView);
    NBRE_String GetWorkPath()const { return mEnv.mWorkPath; }
    PAL_Instance* GetNBPal()const { return mEnv.mPal; }

    // width is pixel value
    virtual void SetLineWidth(float width);

private:
    DISABLE_COPY_AND_ASSIGN(NBRE_D3D11RenderPal);

private:
    void Initialize();
    PAL_Error InitShaders();
    void ResetRasterizerState();
    void ResetDepthStencilState();
    void ResetBlendState();
    uint32 FilterVertexInputFormat(uint32 format);
    void CacheDepthStencialState();
    void CacheBlendState();
    void CacheRasterState();

private:
    NBRE_D3D11RenderWindow* mD3D11RenderWindow;
    NBRE_RenderTarget* mCurrentRenderTarget;
    NBRE_RenderPalCapabilities mCapabilities;
    NBRE_Color mClearColor;
    float mClearDepth;
    int32 mClearStencil;
    int32 *mTextureTypes;
    nb_boolean *mTextureEnables;
    uint32 mLastVertexSourceCount;
    NBRE_D3D11RenderEnv mEnv;
    NBRE_D3D11FixedFuncSimulator *mSimulator;
    NBRE_D3D11GPUPorgramFactory *mShaderFactory;
    D3D11_RASTERIZER_DESC    mRasterizerDesc;
    D3D11_DEPTH_STENCIL_DESC mDepthStencilDesc;
    D3D11_BLEND_DESC         mBlendDesc;
    D3D11_VIEWPORT mViewPort;
    NBRE_PrimitiveType mCurrentPrimitiveType;
    ID3D11InputLayout *mCurrentLayout;
    uint32 mInputVertexFormat;
    nb_boolean mNeedNormalInput;

    struct DepthState
    {
        BOOL DepthEnable;
        D3D11_DEPTH_WRITE_MASK DepthWriteMask;
        ID3D11DepthStencilState* state;
    };
    NBRE_Vector<DepthState> mDepthStateCache;
    nb_boolean mDepthStateCacheValid;

    struct BlendState
    {
        BOOL BlendEnable;
        UINT8 ColorMask;
        ID3D11BlendState* state;
    };
    NBRE_Vector<BlendState> mBlendStateCache;
    nb_boolean mBlendStateCacheValid;

    struct RasterState
    {
        D3D11_CULL_MODE CullMode;
        ID3D11RasterizerState* state;
    };
    NBRE_Vector<RasterState> mRasterStateCache;
    nb_boolean mRasterStateCacheValid;

};

/*! @} */
/*! @} */
#endif