/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SURFACEGRAPH_H
#define SURFACEGRAPH_H

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtWidgets/QSlider>
#include "topographicseries.h"
//#include "highlightseries.h"

//#include "custominputhandler.h"

#include "grid.h"

// using namespace QtDataVisualization;

class SurfaceGraph : public QWidget
{
    Q_OBJECT
public:
    explicit SurfaceGraph(QWidget *parent=nullptr);
    ~SurfaceGraph();

    void setFilename(QString grid_file_name);
    void setup(Grid<float> &dem, float min_h, float max_h);

    void toggleSurfaceTexture(bool enable);
    void clickCamera();

    QtDataVisualization::Q3DSurface *graph() { return m_graph; }
    TopographicSeries *topoSeries() { return m_topography; }
signals:
    void cameraChanged();
private:
    QtDataVisualization::Q3DSurface *m_graph;

    TopographicSeries *m_topography;
    // HighlightSeries *m_highlight;
    int m_highlightWidth;
    int m_highlightHeight;

    //float m_areaWidth;
    //float m_areaHeight;

    Grid<float> *mDem;

    // CustomInputHandler *m_inputHandler;
};

#endif // SURFACEGRAPH_H
