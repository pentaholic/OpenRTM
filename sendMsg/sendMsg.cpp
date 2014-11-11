// -*- C++ -*-
/*!
 * @file  sendMsg.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "sendMsg.h"
#include <iostream>

// Module specification
// <rtc-template block="module_spec">
static const char* sendmsg_spec[] =
  {
    "implementation_id", "sendMsg",
    "type_name",         "sendMsg",
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
sendMsg::sendMsg(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sendMsgOut("sendMsg", m_sendMsg)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sendMsg::~sendMsg()
{
}



RTC::ReturnCode_t sendMsg::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("sendMsg", m_sendMsgOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sendMsg::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
  
char str[100];

/*
未完成です。
１度目は成功するが、2回目は失敗する。
以下エラーコード
----------
*** Error in `./sendMsgComp': free(): invalid pointer: 0x0805c6e0 ***
中止 (コアダンプ)
----------
*/

RTC::ReturnCode_t sendMsg::onExecute(RTC::UniqueId ec_id)
{

  std::cout<<"Input String:"<<std::endl;
  std::cin>>str;
 
  m_sendMsg.data=str;
  std::cout<<"Sending to subscriber:"<<m_sendMsg.data<<std::endl;
  m_sendMsgOut.write();

  delete str;

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sendMsg::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sendMsg::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void sendMsgInit(RTC::Manager* manager)
  {
    coil::Properties profile(sendmsg_spec);
    manager->registerFactory(profile,
                             RTC::Create<sendMsg>,
                             RTC::Delete<sendMsg>);
  }
  
};


