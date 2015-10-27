// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      InputOutput/TiffHandler.h
//! @brief     Defines class TiffHandler.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef TIFFHANDLER_H
#define TIFFHANDLER_H

#ifdef BORNAGAIN_TIFF_SUPPORT

#include "WinDllMacros.h"
#include "OutputData.h"
#include <string>
#include <tiffio.h>
#include <tiffio.hxx>
#include <boost/scoped_ptr.hpp>

//! @class TiffHandler
//! @ingroup input_output
//! @brief Reads/write tiff files, should be used through TiffReadStrategy

class BA_CORE_API_ TiffHandler
{
public:
    TiffHandler();
    ~TiffHandler();

    void read(std::istream& input_stream);

    const OutputData<double> *getOutputData() const;

    void write(const OutputData<double> &data, std::ostream &output_stream);

private:
    void read_header();
    void read_data();
    void write_header();
    void write_data();
    void close();
    void create_output_data();

    TIFF *m_tiff;
    size_t m_width;
    size_t m_height;
    boost::scoped_ptr<OutputData<double> > m_data;
};

#endif // BORNAGAIN_TIFF_SUPPORT

#endif

