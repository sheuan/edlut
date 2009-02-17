#ifndef FILEOUTPUTWEIGHTDRIVER_H_
#define FILEOUTPUTWEIGHTDRIVER_H_

/*!
 * \file FileOutputWeightDriver.h
 *
 * \author Jesus Garrido
 * \date November 2008
 *
 * This file declares a class for write network synaptic weights in a file.
 */
#include "./OutputWeightDriver.h"

class EDLUTException;
class Network;

/*!
 * \class FileOutputWeightDriver
 *
 * \brief Class for communicate synaptic weights in an output file. 
 *
 * This class abstract methods for communicate the synaptic weigths to the target file.
 *
 * \author Jesus Garrido
 * \date November 2008
 */
class FileOutputWeightDriver: public OutputWeightDriver {
	
	private:
	
		/*!
		 * The file handler.
		 */
		FILE * Handler;
		
		/*!
		 * The file name.
		 */
		const char * FileName;
		
	public:
	
		/*!
		 * \brief Class constructor.
		 * 
		 * It creates a new object from the file target.
		 * 
		 * \param NewFileName Name of the target output file. This name will be complemented
		 * with the simulation time.
		 * 
		 * \throw EDLUTException If something wrong happens when the file is been wrotten.
		 */
		FileOutputWeightDriver(const char * NewFileName) throw (EDLUTException);
		
		/*!
		 * \brief Class desctructor.
		 * 
		 * Class desctructor.
		 */
		~FileOutputWeightDriver();
	
		/*!
		 * \brief It communicates the output activity to the external system.
		 * 
		 * This method introduces the network synaptic weights to the output target (file, tcpip system...).
		 * 
		 * \param Net The network to save the weights.
		 * \param SimulationTime The current simulation time.
		 * 
		 * \throw EDLUTException If something wrong happens in the output process.
		 */
		void WriteWeights(Network * Net, float SimulationTime) throw (EDLUTException);
		
		/*!
		 * \brief It communicates the output activity to the external system.
		 * 
		 * This method introduces the network synaptic weights to the output target (file, tcpip system...).
		 * 
		 * \param Net The network to save the weights.
		 * 
		 * \throw EDLUTException If something wrong happens in the output process.
		 */
		void WriteWeights(Network * Net) throw (EDLUTException);
		
};

#endif /*FILEOUTPUTDRIVER_H_*/