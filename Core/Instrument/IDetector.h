// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/IDetector.h
//! @brief     Defines common detector interface.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef IDETECTOR_H_
#define IDETECTOR_H_

#include "IAxis.h"
#include "ICloneable.h"
#include "INode.h"
#include "IUnitConverter.h"
#include "DetectionProperties.h"
#include "SafePointerVector.h"
#include "SimulationAreaIterator.h"

class Beam;
class DetectorElement;
class DetectorMask;
class IDetectorResolution;
class IResolutionFunction2D;
template<class T> class OutputData;
class SimulationElement;
class RegionOfInterest;

//! Abstract detector interface.
//! @ingroup simulation

class BA_CORE_API_ IDetector :  public ICloneable, public INode
{
public:
    using const_iterator = const SimulationAreaIterator&;
    IDetector();

    IDetector* clone() const override =0;

    virtual ~IDetector();

    //! Inits detector with the beam settings
    virtual void init(const Beam&) {}

    void clear() {m_axes.clear();}

    void addAxis(const IAxis& axis);

    const IAxis& getAxis(size_t index) const;

    //! Returns actual dimensionality of the detector (number of defined axes)
    size_t dimension() const {return m_axes.size();}

    //! Calculate axis index for given global index
    size_t axisBinIndex(size_t index, size_t selected_axis) const;

    //! Returns total number of pixels
    size_t totalSize() const;

    //! Returns detector masks container
    virtual const DetectorMask* detectorMask() const = 0;

    //! Sets the polarization analyzer characteristics of the detector
    void setAnalyzerProperties(const kvector_t direction, double efficiency,
                               double total_transmission);

    //! Sets the detector resolution
    void setDetectorResolution(const IDetectorResolution& p_detector_resolution);
    void setResolutionFunction(const IResolutionFunction2D& resFunc);

    //! Applies the detector resolution to the given intensity maps
    void applyDetectorResolution(OutputData<double>* p_intensity_map) const;

    //! Removes detector resolution function.
    void removeDetectorResolution();

    //! Returns a pointer to detector resolution object
    const IDetectorResolution* detectorResolution() const;

#ifndef SWIG
    //! Returns empty detector map in given axes units.
    std::unique_ptr<OutputData<double>> createDetectorMap() const;

    //! Create a vector of DetectorElement objects according to the detector and its mask
    virtual std::vector<DetectorElement> createDetectorElements(const Beam& beam) =0;
#endif // SWIG

    //! Returns region of  interest if exists.
    virtual const RegionOfInterest* regionOfInterest() const = 0;

    //! Resets region of interest making whole detector plane available for the simulation.
    virtual void resetRegionOfInterest() = 0;

    //! Returns detection properties
    const DetectionProperties& detectionProperties() const {return m_detection_properties;}

    //! Returns new intensity map with detector resolution applied. Map will be cropped to ROI
    //! if ROI is present.
    OutputData<double>* createDetectorIntensity(
            const std::vector<SimulationElement>& elements) const;

    //! Return default axes units
    virtual AxesUnits defaultAxesUnits() const {return AxesUnits::DEFAULT;}

    //! Returns number of simulation elements.
    size_t numberOfSimulationElements() const;

    std::vector<const INode*> getChildren() const override;

    void iterate(std::function<void(const_iterator)> func, bool visit_masks=false) const;

protected:
    IDetector(const IDetector& other);

    //! Returns the name for the axis with given index
    virtual std::string axisName(size_t index) const = 0;

    //! Generates an axis with correct name and default binning for given index
    virtual std::unique_ptr<IAxis> createAxis(size_t index, size_t n_bins, double min,
                                              double max) const;

private:
    void setDataToDetectorMap(OutputData<double>& detectorMap,
                              const std::vector<SimulationElement>& elements) const;

    SafePointerVector<IAxis> m_axes;
    DetectionProperties m_detection_properties;
    std::unique_ptr<IDetectorResolution> mP_detector_resolution;
};

#endif /* IDETECTOR_H_ */
