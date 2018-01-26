// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/MaterialDataItems.cpp
//! @brief     Implements MaterialDataItems classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MaterialDataItems.h"

MaterialDataItem::MaterialDataItem(const QString& modelType)
    : SessionItem(modelType)
{
    setEditable(false); // empty label, non-editable
}

// ------------------------------------------------------------------------------------------------

const QString MaterialRefractiveDataItem::P_DELTA = "Delta";
const QString MaterialRefractiveDataItem::P_BETA = "Beta";

MaterialRefractiveDataItem::MaterialRefractiveDataItem()
    : MaterialDataItem(Constants::MaterialRefractiveDataType)
{
    addProperty(P_DELTA, 0.0)->setEditorType(Constants::ScientificEditorType)
        .setLimits(RealLimits::limitless())
        .setToolTip("Delta of refractive index (n = 1 - delta + i*beta)");
    addProperty(P_BETA, 0.0)->setEditorType(Constants::ScientificEditorType)
        .setLimits(RealLimits::limitless())
        .setToolTip("Beta of refractive index (n = 1 - delta + i*beta)");
}

// ------------------------------------------------------------------------------------------------

const QString MaterialSLDDataItem::P_SLD = "SLD";
const QString MaterialSLDDataItem::P_ABS_TERM = "Absorption";

MaterialSLDDataItem::MaterialSLDDataItem()
    : MaterialDataItem(Constants::MaterialSLDDataType)
{
    addProperty(P_SLD, 0.0)->setEditorType(Constants::ScientificEditorType)
        .setLimits(RealLimits::limitless())
        .setToolTip("Scattering length density");
    addProperty(P_ABS_TERM, 0.0)->setEditorType(Constants::ScientificEditorType)
        .setLimits(RealLimits::limitless())
        .setToolTip("Absorption cross-section")
        .setDisplayName("Absorption term");
}
