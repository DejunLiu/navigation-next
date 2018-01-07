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

    @file nbreiboundtree2d.h
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
#ifndef _NBRE_AABB_TREE_2D_H_
#define _NBRE_AABB_TREE_2D_H_
#include "nbretypes.h"
#include "nbreicollisionprimitive.h"
#include "nbreaxisalignedbox2.h"
#include "nbreiboundtree2d.h"

/*! \addtogroup NBRE_Scene
*  @{
*/
/** AABB Tree is a in-object BVH structure which improves pairwise object-object collision test.
 */
class NBRE_AABBTree2d:
    public NBRE_IBoundTree2d
{
    /** Tree node is either a primitive node(leaf) or a aabb node.
    */
    struct Node
    {
    public:
        Node(NBRE_ICollisionPrimitive2d* obj);
        ~Node();
        nb_boolean HitTest(NBRE_ICollisionPrimitive2d* obj);
        const NBRE_AxisAlignedBox2d& GetAABB() { return mPrimitive ? mPrimitive->GetAABB() : mAABB; }

    public:
        NBRE_AxisAlignedBox2d mAABB;
        NBRE_ICollisionPrimitive2d* mPrimitive;
        Node* mChildNodes[2];
    };
public:
    NBRE_AABBTree2d();
    virtual ~NBRE_AABBTree2d();
    virtual nb_boolean HitTest(NBRE_ICollisionPrimitive2d* obj);
    virtual nb_boolean HitTest(NBRE_IBoundTree2d* tree);
    virtual const NBRE_AxisAlignedBox2d& GetAABB() { return mRoot->GetAABB(); }
    virtual void BuildTree(NBRE_ICollisionPrimitive2d** primitives, uint32 count);
    void GetNodeAABBs(NBRE_Vector<NBRE_AxisAlignedBox2d>& aabbs);
    void GetPrimitives(NBRE_Vector<NBRE_ICollisionPrimitive2d*>& result);

private:
    void BuildNode(Node** node, NBRE_ICollisionPrimitive2d** primitives, uint32 beginIndex, uint32 endIndex);
    uint32 SplitPrimitives(NBRE_ICollisionPrimitive2d** primitives, uint32 beginIndex, uint32 endIndex);
    void CalculateAABB(NBRE_ICollisionPrimitive2d** primitives, uint32 beginIndex, uint32 endIndex, NBRE_AxisAlignedBox2d& result);
    double GetAABBArea(const NBRE_AxisAlignedBox2d& aabb);
    double GetSplitTotalArea(NBRE_ICollisionPrimitive2d** primitives, uint32 beginIndex, uint32 endIndex, uint32 splitFrom);

private:
    Node* mRoot;
};

/*! @} */
#endif