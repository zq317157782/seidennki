//
// Created by 诸谦 on 15/12/28.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H


#include <Intersection.h>
#include "global.h"
#include "memory.h"
#include "geometry.h"

using namespace std;

class Shape :public ReferenceCounted{
protected:
    static unsigned int nextShapeID;
public:
    const Transform * localToWorld;
    const Transform * worldToLocal;

    const unsigned int shapeID;

    const bool ReverseOrientation, TransformSwapsHandedness;
public:
    Shape(const Transform *o2w,const Transform *w2o,bool ro);
    /*判断与法线的碰撞*/
    virtual bool Intersect(const Ray& ray,float* distance,float *rayEpsilon, DifferentialGeometry *dg) const;
    virtual bool IntersectP(const Ray& ray) const;
    virtual bool CanIntersect() const;
    virtual void Refine(vector<Reference<Shape> > &refined) const;//提炼函数  为一些几何体提炼更加合适的几何结构

    //获取着色用的微分几何结构的函数 默认直接返回原微分几何结构
    virtual void GetShadingGeometry(const Transform &obj2world,
               const DifferentialGeometry &dg,
               DifferentialGeometry *dgShading) const {
           *dgShading = dg;
       }
    virtual float Area() const;
    virtual ~Shape(){};
};


#endif //RAYTRACER_SHAPE_H
