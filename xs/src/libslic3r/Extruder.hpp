#ifndef slic3r_Extruder_hpp_
#define slic3r_Extruder_hpp_

#include "libslic3r.h"
#include "Point.hpp"
#include "PrintConfig.hpp"

namespace Slic3r {

class Extruder
{
    public:
    /// ID of current object.
    unsigned int id;
    double E;
    double absolute_E;
    double retracted;
    double restart_extra;
    double e_per_mm3;
    double retract_speed_mm_min;
    
    bool angled_e;
    double extruder_len;
    double extruder_wid;
    Extruder(unsigned int id, GCodeConfig *config);
    virtual ~Extruder() {}
    void reset();
    /// Calculate the amount extruded for relative or absolute moves.
    double extrude(double dE, double dx, double dy);

    double retract(double length, double restart_extra);
    double unretract();
    double e_per_mm(double mm3_per_mm) const;
    double extruded_volume() const;
    
    /// Calculate amount of filament used for current Extruder object.
    double used_filament() const;
  
    /// Retrieve the filament diameter for this Extruder from config.
    double filament_diameter() const;
    /// Retrieve the filament density for this Extruder from config.
    double filament_density() const;
    /// Retrieve the filament cost for this Extruder from config.
    double filament_cost() const;
    /// Retrieve the extrustion multiplier for this Extruder from config.
    double extrusion_multiplier() const;
    double retract_length() const;
    double retract_lift() const;
    int retract_speed() const;
    double retract_restart_extra() const;
    double retract_length_toolchange() const;
    double retract_restart_extra_toolchange() const;
    
    bool use_angled_extruder() const;
    double angled_extruder_width() const;
    double angled_extruder_height() const;
    private:
    GCodeConfig *config;
};

}

#endif
