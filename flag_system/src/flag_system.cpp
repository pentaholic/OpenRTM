// -*- C++ -*-
/*!
 * @file  flag_system.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "flag_system.h"

// Module specification
// <rtc-template block="module_spec">
static const char* flag_system_spec[] =
  {
    "implementation_id", "flag_system",
    "type_name",         "flag_system",
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
flag_system::flag_system(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_user_headIn("user_head", m_user_head),
    m_user_neckIn("user_neck", m_user_neck),
    m_user_left_shoulderIn("user_left_shoulder", m_user_left_shoulder),
    m_user_left_elbowIn("user_left_elbow", m_user_left_elbow),
    m_user_left_handIn("user_left_hand", m_user_left_hand),
    m_user_right_shoulderIn("user_right_shoulder", m_user_right_shoulder),
    m_user_right_elbowIn("user_right_elbow", m_user_right_elbow),
    m_user_right_handIn("user_right_hand", m_user_right_hand),
    m_user_torsoIn("user_torso", m_user_torso),
    m_check_gestureOut("check_gesture", m_check_gesture)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
flag_system::~flag_system()
{
}



RTC::ReturnCode_t flag_system::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("user_head", m_user_headIn);
  addInPort("user_neck", m_user_neckIn);
  addInPort("user_left_shoulder", m_user_left_shoulderIn);
  addInPort("user_left_elbow", m_user_left_elbowIn);
  addInPort("user_left_hand", m_user_left_handIn);
  addInPort("user_right_shoulder", m_user_right_shoulderIn);
  addInPort("user_right_elbow", m_user_right_elbowIn);
  addInPort("user_right_hand", m_user_right_handIn);
  addInPort("user_torso", m_user_torsoIn);
  
  // Set OutPort buffer
  addOutPort("check_gesture", m_check_gestureOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_system::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t flag_system::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_system::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_system::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void flag_systemInit(RTC::Manager* manager)
  {
    coil::Properties profile(flag_system_spec);
    manager->registerFactory(profile,
                             RTC::Create<flag_system>,
                             RTC::Delete<flag_system>);
  }
  
};


