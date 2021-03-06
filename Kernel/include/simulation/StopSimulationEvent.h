/***************************************************************************
 *                           StopSimulationEvent.h                         *
 *                           -------------------                           *
 * copyright            : (C) 2009 by Jesus Garrido                        *
 * email                : jgarrido@atc.ugr.es                              *
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef STOPSIMULATIONEVENT_H_
#define STOPSIMULATIONEVENT_H_

/*!
 * \file StopSimulationEvent.h
 *
 * \author Jesus Garrido
 * \date October 2009
 *
 * This file declares a class which abstracts a simulation event to stop the simulation.
 */
 
#include <iostream>

#include "./Event.h"

using namespace std;

class Simulation;

/*!
 * \class StopSimulationEvent
 *
 * \brief Simulation abstract event to stop the simulation.
 *
 * This class abstract the concept of event to stop the simulation.
 *
 * \author Jesus Garrido
 * \date October 2009
 */
class StopSimulationEvent: public Event{
	
	public:
   		
   		/*!
   		 * \brief Default constructor.
   		 * 
   		 * It creates and initializes a new event object.
   		 */
   		StopSimulationEvent();
   	
   		/*!
   		 * \brief Constructor with parameters.
   		 * 
   		 * It creates and initializes a new event with the parameters.
   		 * 
   		 * \param NewTime Time of the new event.
   		 */
   		StopSimulationEvent(double NewTime);
   		
   		/*!
   		 * \brief Class destructor.
   		 * 
   		 * It destroies an object of this class.
   		 */
   		~StopSimulationEvent();
   	

 		/*!
   		 * \brief It process an event in the simulation.
   		 * 
   		 * It process the event in the simulation.
   		 * 
   		 * \param CurrentSimulation The simulation object where the event is working.
		 * \param RealTimeRestriction This variable indicates whether we are making a 
		 * real-time simulation and the watchdog is enabled.
   		 */
   		virtual void ProcessEvent(Simulation * CurrentSimulation, bool RealTimeRestriction);
};

#endif /*STOPSIMULATIONEVENT_H_*/
