#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
 public:
  PayOff() {};
  virtual double operator() (double spot) const = 0;
  virtual  ~PayOff() {}
  virtual PayOff* clone() const;
private:
  
};

class PayOffCall : public PayOff
{
 public:
  PayOffCall(double strike);
  virtual double operator() (double Spot) const;
  virtual  ~PayOffCall(){}
  virtual PayOff* clone() const;
 private:
  double strike;
};

class PayOffPut : public PayOff
{
public:
  PayOffPut(double strike);
  virtual double operator() (double Spot) const;
  virtual ~PayOffPut(){}
  virtual PayOff* clone() const;
private:
  double strike;
};

class PayOffDigitalPut : public PayOff
{
public:
  PayOffDigitalPut(double strike);
  virtual double operator() (double Spot) const;
  virtual ~PayOffDigitalPut(){}
  virtual PayOff *clone() const;
private:
  double strike;
};


class PayOffDigitalCall : public PayOff
{
public:
  PayOffDigitalCall(double strike);
  virtual double operator() (double Spot) const;
  virtual ~PayOffDigitalCall(){}
    virtual PayOff *clone() const;
private:
  double strike;
};

class PayOffDoubleDigital : public PayOff
{
public:
  PayOffDoubleDigital(double ll, double ul);
  virtual double operator() (double Spot) const;
  virtual ~PayOffDoubleDigital(){}
    virtual PayOff *clone() const;
private:
  double lower_level;
  double upper_level;
};


#endif
