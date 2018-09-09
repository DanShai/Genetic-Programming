
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef DATAXY_H
#define DATAXY_H

class DataXy
{
    /**
	 * helper class to repersent our data points for the regression!
	 *
	 */

  public:
    DataXy(int x, int y);
    virtual ~DataXy();
    int getX();
    int getY();

  private:
    int xF;
    int yF;
};

#endif /* DATAXY_H */
#endif	/* DATAXY_H */
