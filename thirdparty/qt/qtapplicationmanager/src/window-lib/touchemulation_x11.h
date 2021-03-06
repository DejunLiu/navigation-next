/****************************************************************************
**
** Copyright (C) 2017 Pelagicore AG
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Pelagicore Application Manager.
**
** $QT_BEGIN_LICENSE:LGPL-QTAS$
** Commercial License Usage
** Licensees holding valid commercial Qt Automotive Suite licenses may use
** this file in accordance with the commercial license agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and The Qt Company.  For
** licensing terms and conditions see https://www.qt.io/terms-conditions.
** For further information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
** SPDX-License-Identifier: LGPL-3.0
**
****************************************************************************/

#pragma once

#include <QtAppManCommon/global.h>
#include "touchemulation.h"

#if defined(AM_ENABLE_TOUCH_EMULATION)

#include <QAbstractNativeEventFilter>
#include <QObject>
#include <QWindow>

QT_FORWARD_DECLARE_CLASS(QTouchDevice)
QT_FORWARD_DECLARE_CLASS(QWindow)

QT_BEGIN_NAMESPACE_AM

class TouchEmulationX11 : public TouchEmulation, public QAbstractNativeEventFilter
{
public:
    TouchEmulationX11();
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;

private:
    void queryForXInput2();
    bool handleButtonPress(WId windowId, uint32_t detail, uint32_t modifiers, int x, int y);
    bool handleButtonRelease(WId windowId, uint32_t detail, uint32_t, int x, int y);
    bool handleMotionNotify(WId windowId, uint32_t modifiers, int x, int y);
    QWindow *findQWindowWithXWindowID(WId windowId);

    QTouchDevice *m_touchDevice = nullptr;
    bool m_haveXInput2 = false;
    bool m_leftButtonIsPressed = false;
};

QT_END_NAMESPACE_AM

#endif // AM_ENABLE_TOUCH_EMULATION
