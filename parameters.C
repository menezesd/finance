#include "parameters.h"

Parameters::Parameters(const ParametersInner& innerObject)
{
    InnerObjectPtr = innerObject.clone();

}

Parameters::Parameters(const Parameters& original)
{

    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original)
{

    if (this != &original)
    {

         delete InnerObjectPtr;
         InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}

Parameters::~Parameters()
{

    delete InnerObjectPtr;
}

double Parameters::mean(double time1, double time2) const
{

    double total = integral(time1,time2);
    return total/(time2-time1);
}

double Parameters::root_mean_square(double time1,
                                                      double time2) const
{

    double total = integral_square(time1,time2);
    return total/(time2-time1);
}

ParametersConstant::ParametersConstant(double constant)
{
    Constant = constant;
    ConstantSquare = Constant*Constant;

}

ParametersInner* ParametersConstant::clone() const
{

    return new ParametersConstant(*this);
}
double ParametersConstant::integral(double time1,
                                                         double time2) const

{
    return (time2-time1)*Constant;

}
double ParametersConstant::integral_square(double time1,
                                                                  double time2) const

{
    return (time2-time1)*ConstantSquare;
}


