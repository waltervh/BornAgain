// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorIcosahedron.h
//! @brief     Defines class FormFactorIcosahedron.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FORMFACTORICOSAHEDRON_H
#define FORMFACTORICOSAHEDRON_H

#include "FormFactorPolyhedron.h"

//! A regular icosahedron.
//! @ingroup hardParticle

class BA_CORE_API_ FormFactorIcosahedron : public FormFactorPolyhedron
{
public:
    FormFactorIcosahedron(double edge);

    FormFactorIcosahedron *clone() const override final {
        return new FormFactorIcosahedron(m_edge); }
    void accept(INodeVisitor *visitor) const override final { visitor->visit(this); }

    double getEdge() const { return m_edge; }

protected:
    void onChange() override final;

private:
    static const PolyhedralTopology topology;
    double m_edge;
};

#endif // FORMFACTORICOSAHEDRON_H
