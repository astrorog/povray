//******************************************************************************
///
/// @file core/shape/sphere.h
///
/// This module contains all defines, typedefs, and prototypes for
/// @ref sphere.cpp.
///
/// @copyright
/// @parblock
///
/// Persistence of Vision Ray Tracer ('POV-Ray') version 3.7.
/// Copyright 1991-2015 Persistence of Vision Raytracer Pty. Ltd.
///
/// POV-Ray is free software: you can redistribute it and/or modify
/// it under the terms of the GNU Affero General Public License as
/// published by the Free Software Foundation, either version 3 of the
/// License, or (at your option) any later version.
///
/// POV-Ray is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU Affero General Public License for more details.
///
/// You should have received a copy of the GNU Affero General Public License
/// along with this program.  If not, see <http://www.gnu.org/licenses/>.
///
/// ----------------------------------------------------------------------------
///
/// POV-Ray is based on the popular DKB raytracer version 2.12.
/// DKBTrace was originally written by David K. Buck.
/// DKBTrace Ver 2.0-2.12 were written by David K. Buck & Aaron A. Collins.
///
/// @endparblock
///
//******************************************************************************

#ifndef SPHERES_H
#define SPHERES_H

#include "backend/scene/objects.h"

namespace pov
{

/*****************************************************************************
* Global preprocessor defines
******************************************************************************/

#define SPHERE_OBJECT (BASIC_OBJECT)


/*****************************************************************************
* Global typedefs
******************************************************************************/

class Sphere : public ObjectBase
{
    public:
        Vector3d Center;
        DBL Radius;

        Sphere();
        virtual ~Sphere();

        virtual ObjectPtr Copy();

        virtual bool All_Intersections(const Ray&, IStack&, TraceThreadData *);
        virtual bool Inside(const Vector3d&, TraceThreadData *) const;
        virtual void Normal(Vector3d&, Intersection *, TraceThreadData *) const;
        virtual void UVCoord(Vector2d&, const Intersection *, TraceThreadData *) const;
        virtual void Translate(const Vector3d&, const TRANSFORM *);
        virtual void Rotate(const Vector3d&, const TRANSFORM *);
        virtual void Scale(const Vector3d&, const TRANSFORM *);
        virtual void Transform(const TRANSFORM *);
        virtual void Compute_BBox();
        virtual bool Intersect_BBox(BBoxDirection, const BBoxVector3d&, const BBoxVector3d&, BBoxScalar) const;

        static bool Intersect(const BasicRay& ray, const Vector3d& Center, DBL Radius2, DBL *Depth1, DBL  *Depth2);
    private:
        bool Do_Ellipsoid; // TODO - parser needs to take care of this
};

}

#endif
