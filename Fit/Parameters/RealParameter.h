// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/RealParameter.h
//! @brief     Declares class RealParameter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef REALPARAMETERWRAPPER_H
#define REALPARAMETERWRAPPER_H

#include "INamed.h" // inheriting from
#include "AttLimits.h"
#include <string>

class IParameterized;

//! Wrapper to real parameter for remote access to its value and callback abilities
//! @class RealParameter
//! @ingroup tools_internal

class BA_CORE_API_ RealParameter : public INamed {
public:
    explicit RealParameter(
        const std::string& name, IParameterized* parent,
        volatile double* par, const AttLimits& limits=AttLimits::limitless());
    RealParameter(const RealParameter& other);
    RealParameter(const std::string& name, const RealParameter& other);

    //! Sets value of wrapped parameter and emit signal
    void setValue(double value);

    //! Returns value of wrapped parameter
    double getValue() const { checkNull(); return *m_data; }

    //! Returns true if wrapped parameter was not initialized with proper real value
    bool isNull() const { return m_data ? false : true; }

    //! throw exception if parameter was not initialized with proper value
    void checkNull() const;

    //! Prints the parameter's address to an output stream
    friend std::ostream& operator<<(std::ostream& ostr, const RealParameter& p) {
        ostr << p.m_data; return ostr; }

    AttLimits getAttLimits() const { return m_limits; }

    bool operator==(const RealParameter &other) const {
        return (m_limits == other.m_limits) && (m_data == other.m_data); }
    bool operator!=(const RealParameter &other) const { return !(*this == other); }

private:
    void swapContent(RealParameter& other);

    IParameterized* m_parent; //!< IParametrized object that "owns" this pool
    std::string m_name;
    volatile double* m_data;
    AttLimits m_limits;
    std::string fullName(); //!< For use in error messages
};

#endif // REALPARAMETERWRAPPER_H