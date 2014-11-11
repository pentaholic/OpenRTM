// -*- C++ -*-
/*!
 * @file  recvMsg.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "recvMsg.h"

// Module specification
// <rtc-template block="module_spec">
static const char* recvmsg_spec[] =
  {
    "implementation_id", "recvMsg",
    "type_name",         "recvMsg",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
recvMsg::recvMsg(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_recvMsgIn("recvMsg", m_recvMsg)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
recvMsg::~recvMsg()
{
}



RTC::ReturnCode_t recvMsg::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("recvMsg", m_recvMsgIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t recvMsg::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t recvMsg::onExecute(RTC::UniqueId ec_id)
{
  if(m_recvMsgIn.isNew()){
    m_recvMsgIn.read();

    std::cout<<"Received:"<<m_recvMsg.data<<std::endl;

  }

  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t recvMsg::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t recvMsg::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void recvMsgInit(RTC::Manager* manager)
  {
    coil::Properties profile(recvmsg_spec);
    manager->registerFactory(profile,
                             RTC::Create<recvMsg>,
                             RTC::Delete<recvMsg>);
  }
  
};


