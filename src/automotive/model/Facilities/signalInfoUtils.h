/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 * Created by:
 *  Diego Gasco, Politecnico di Torino (diego.gasco@polito.it, diego.gasco99@gmail.com)
*/

#ifndef SIGNALINFOUTILS_H
#define SIGNALINFOUTILS_H
#include <string>
#include <cmath>
#include <fstream>

const double DEFAULT_VALUE = std::numeric_limits<double>::quiet_NaN();
const double SENTINEL_VALUE = 42000;

typedef struct {
    double timestamp;
    double rssi;
    double snr;
    double sinr;
    double rsrp;
    double size;
} SignalInfo;


class SignalInfoUtils
{
public:
    SignalInfoUtils();
    void SetSignalInfo(double timestamp, double size, double rssi, double snr, double sinr, double rsrp);
    SignalInfo GetSignalInfo();
    void WriteLastSignalInfo(std::string path, long stationID);

private:
    SignalInfo m_signalInfo;
};


#endif // SIGNALINFOUTILS_H
