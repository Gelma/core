/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_CHART2_SOURCE_VIEW_CHARTTYPES_AREACHART_HXX
#define INCLUDED_CHART2_SOURCE_VIEW_CHARTTYPES_AREACHART_HXX

#include "VSeriesPlotter.hxx"
#include <com/sun/star/chart2/CurveStyle.hpp>

namespace chart
{

class AreaChart : public VSeriesPlotter
{
    // public methods
public:
    AreaChart( const ::com::sun::star::uno::Reference<
             ::com::sun::star::chart2::XChartType >& xChartTypeModel
             , sal_Int32 nDimensionCount
             , bool bCategoryXAxis, bool bNoArea=false
             );
    virtual ~AreaChart();

    virtual void createShapes() override;
    virtual void addSeries( VDataSeries* pSeries, sal_Int32 zSlot = -1, sal_Int32 xSlot = -1,sal_Int32 ySlot = -1 ) override;

    virtual ::com::sun::star::drawing::Direction3D  getPreferredDiagramAspectRatio() const override;

    // MinimumAndMaximumSupplier
    virtual double getMaximumX() override;
    virtual bool isExpandIfValuesCloseToBorder( sal_Int32 nDimensionIndex ) override;
    virtual bool isSeparateStackingForDifferentSigns( sal_Int32 nDimensionIndex ) override;

    virtual LegendSymbolStyle getLegendSymbolStyle() override;
    virtual ::com::sun::star::uno::Any getExplicitSymbol( const VDataSeries& rSeries, sal_Int32 nPointIndex=-1/*-1 for series symbol*/ ) override;

private: //methods
    //no default constructor
    AreaChart();

    void impl_createSeriesShapes();
    bool impl_createArea( VDataSeries* pSeries
                , ::com::sun::star::drawing::PolyPolygonShape3D* pSeriesPoly
                , ::com::sun::star::drawing::PolyPolygonShape3D* pPreviousSeriesPoly
                , PlottingPositionHelper* pPosHelper );
    bool impl_createLine( VDataSeries* pSeries
                , ::com::sun::star::drawing::PolyPolygonShape3D* pSeriesPoly
                , PlottingPositionHelper* pPosHelper );
    static bool create_stepped_line( ::com::sun::star::drawing::PolyPolygonShape3D aStartPoly
                , ::com::sun::star::chart2::CurveStyle eCurveStyle
                , PlottingPositionHelper* pPosHelper
                , ::com::sun::star::drawing::PolyPolygonShape3D &aPoly );

private: //member
    PlottingPositionHelper*             m_pMainPosHelper;

    bool                                m_bArea;//false -> line or symbol only
    bool                                m_bLine;
    bool                                m_bSymbol;

    //Properties for splines:
    ::com::sun::star::chart2::CurveStyle    m_eCurveStyle;
    sal_Int32                                       m_nCurveResolution;
    sal_Int32                                       m_nSplineOrder;

    ::com::sun::star::uno::Reference<
                    ::com::sun::star::drawing::XShapes > m_xSeriesTarget;
    ::com::sun::star::uno::Reference<
                    ::com::sun::star::drawing::XShapes > m_xErrorBarTarget;
    ::com::sun::star::uno::Reference<
                    ::com::sun::star::drawing::XShapes > m_xTextTarget;
    ::com::sun::star::uno::Reference<
                    ::com::sun::star::drawing::XShapes > m_xRegressionCurveEquationTarget;
};
} //namespace chart
#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
