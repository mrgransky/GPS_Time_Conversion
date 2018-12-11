#include <iostream>
#include <vector>

using namespace std;

// Define GPS leap sec
vector<double> getLeaps()
{
	vector<double> leaps;

	leaps.push_back(46828800);
	leaps.push_back(78364801);
	leaps.push_back(109900802);
	leaps.push_back(173059203);

	leaps.push_back(252028804);
	leaps.push_back(315187205);
	leaps.push_back(346723206);
	leaps.push_back(393984007);

	leaps.push_back(425520008);
	leaps.push_back(457056009);
	leaps.push_back(504489610);
	leaps.push_back(551750411);

	leaps.push_back(599184012);
	leaps.push_back(820108813);
	leaps.push_back(914803214);
	leaps.push_back(1025136015);

	leaps.push_back(1119744016);
	leaps.push_back(1167264017);

	return leaps;
}


bool isLeap(double gpsTime)
{
	bool leapExist = false;
	vector<double> leaps;
	
	leaps = getLeaps();
	
	for(int i = 0; i < leaps.size(); i++)
	{
		if(gpsTime == leaps[i])
		{
			leapExist = true;
		}
	}

	return leapExist;	
}

double countLeaps(double gpsTime)
{
	double nLeaps;
	vector<double> leaps;

	leaps = getLeaps();

	cout << "size of leaps = " << leaps.size() << endl;

	for(int i = 0; i < leaps.size(); i++)
	{
		if (gpsTime >= leaps[i])
		{
			nLeaps++;
		}
	}


	return nLeaps;
}

double gps2unix(long gpsTime)
{
	double unixTime;
	double nLeaps;

	unixTime = gpsTime + 315964800;

	nLeaps = countLeaps(gpsTime);

	unixTime = unixTime - nLeaps;

	if (isLeap(gpsTime)) 
	{
		unixTime = unixTime + 0.5;
	}

	return unixTime;
}

double unix2gps(double unixTime)
{

}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cerr << "Syntax: \n\n" << argv[0] << " [GPS_TIME]" << endl;
		return -1;
	}

	long utc;	
	utc = gps2unix(atof(argv[1]));
	
	cout << "GPS_Time = " << argv[1] << " , Unix = " << utc << endl;
	return 0;
}

