// -*- C++ -*-
/*!
 * @file  flag_system.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "flag_system.h"
#include <math.h>
#include <vector>

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
  

  std::vector<int> pattern;//パターンログを20個格納する


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

//手肩の直線と手肘の直線が交わる角度
  double line(double slope1,double slope2,double angle){
	double l1,l2;
	double th;
	double x;

	l1=slope1;
	l2=slope2;
	x=angle;//設定角度

	th=(l2-l1)/(1+l1*l2);//２直線の交わる角度(0<theta<180)

	if(-fabs(th)<x&&x<fabs(th)){
		std::cout<<("\ntrue\n")<<std::endl;
		return true;
	}else
		std::cout<<("\nfalse\n")<<std::endl;
		return false;
  }


RTC::ReturnCode_t flag_system::onExecute(RTC::UniqueId ec_id)
{
  m_user_headIn.read();//head
  m_user_neckIn.read();//neck
  m_user_left_shoulderIn.read();//left shoulder
  m_user_left_elbowIn.read();//left elbow
  m_user_left_handIn.read();//left hand
  m_user_right_shoulderIn.read();//right shoulder
  m_user_right_elbowIn.read();//right elbow
  m_user_right_handIn.read();//right hand

//X座標
  double xhead		=	m_user_head.data.x;
  double xneck		=	m_user_neck.data.x;
  double r_xshoulder	=	m_user_right_shoulder.data.x;
  double r_xelbow	=	m_user_right_elbow.data.x;	
  double r_xhand	=	m_user_right_hand.data.x;
  double l_xshoulder	=	m_user_left_shoulder.data.x;
  double l_xelbow	=	m_user_left_elbow.data.x;	
  double l_xhand	=	m_user_left_hand.data.x;
//Y座標
  double yhead		=	m_user_head.data.y;
  double yneck		=	m_user_neck.data.y;
  double r_yshoulder	=	m_user_right_shoulder.data.y;
  double r_yelbow	=	m_user_right_elbow.data.y;	
  double r_yhand	=	m_user_right_hand.data.y;
  double l_yshoulder	=	m_user_left_shoulder.data.y;
  double l_yelbow	=	m_user_left_elbow.data.y;	
  double l_yhand	=	m_user_left_hand.data.y;
//Z座標
  double zhead		=	m_user_head.data.z;
  double zneck		=	m_user_neck.data.z;
  double r_zshoulder	=	m_user_right_shoulder.data.z;
  double r_zelbow	=	m_user_right_elbow.data.z;	
  double r_zhand	=	m_user_right_hand.data.z;
  double l_zshoulder	=	m_user_left_shoulder.data.z;
  double l_zelbow	=	m_user_left_elbow.data.z;	
  double l_zhand	=	m_user_left_hand.data.z;


  double r_slope	=(r_yshoulder - r_yhand) / (r_xshoulder - r_xhand);//右肩右手の傾き
  double l_slope	=(l_yshoulder - l_yhand) / (l_xshoulder - l_xhand);//左肩左手の傾き  

  double zspace=300;//肩と手のz座標の誤差設定。zが大きすぎる場合、認識しないようにする。30cm
  double theta=M_PI/8;

  std::cout<<"r_slope="	<<r_slope	<<"l_slope="	<<l_slope<<std::endl;



/////////////////////////////////////////////////パターン//////////////////////////////////////////////////


//基本姿勢
//ok。胴体後ろの可動域が広い。前部分は極端に狭く感じる。設定を見直すとベスト。
  if((tan(11*theta)<r_slope	||	r_slope<tan(13*theta))	//11*pi/8<右肩、右肩<13*pi/8	tan(11*pi/8)≒2.3 
	&&(tan(11*theta)<l_slope||	l_slope<tan(13*theta))	//11*pi/8<左肩、左肩<13*pi/8
	&&r_yshoulder>r_yhand	//右肩のy座標>右手のy距離
	&&l_yshoulder>l_yhand	//左肩の座標>左手のy距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\n基本姿勢\n"<<std::endl;	

		pattern.push_back(100);//末尾に括弧内の数字を追加
		
	}


//パターン1ok
  else if((tan(7*theta)<r_slope	&&	r_slope<tan(9*theta))	//tan(7*pi/8)<右肩<tan(9*pi/8)	
	&&(tan(-theta)<l_slope	&&	l_slope<tan(theta))	//tan(-pi/8)<左肩<tan(pi/8)
	&&fabs(r_yshoulder-r_yelbow)<150	//右肘のy座標-右肩のy座標<15cm以下
	&&fabs(l_yshoulder-l_yelbow)<150	//左肘のy座標-左肩のy座標<15cm以下
	&&fabs(r_zhand-zhead)<zspace	//右肩のz座標-頭のz座標の絶対値<15cm以下※要検討
	&&fabs(l_zhand-zhead)<zspace	//左肩のz座標-頭のz座標の絶対値<15cm以下※要検討
	){
		std::cout<<"\nパターン１\n"<<std::endl;		

		pattern.push_back(1);//末尾に括弧内の数字を追加
	}


//パターン2-1ok
  else if((r_slope<tan(5*theta)||tan(3*theta)<r_slope)	//右肩<tan(5*pi/8)、tan(3*pi/8)<右肩
	&&(tan(11*theta)<l_slope||l_slope<tan(13*theta))	//tan(11*pi/8)<左肩、左肩<tan(13*pi/8)
	&&r_yshoulder<r_yhand	//右肩のy座標<右手のy距離
	&&l_yshoulder>l_yhand	//左肩の座標>左手のy距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン２−１\n"<<std::endl;		

		pattern.push_back(21);//末尾に括弧内の数字を追加
	}


//パターン2-2ok
  else if((tan(11*theta)<r_slope	||r_slope<tan(13*theta))	//tan(11*pi/8)<右肩、右肩<tan(13*pi/8)
	&&(l_slope<tan(5*theta)||tan(3*theta)<l_slope)	//左肩<tan(5*pi/8)、tan(3*pi/8)<左肩
	&&r_yshoulder>r_yhand	//右肩のy座標>右手のy距離
	&&l_yshoulder<l_yhand	//左肩の座標<左手のy距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン２−２\n"<<std::endl;		

		pattern.push_back(22);//末尾に括弧内の数字を追加
	}




//パターン3ok
  else if((tan(5*theta)<r_slope	&&	r_slope<tan(7*theta))	//tan(5*pi/8)<右肩<tan(7*pi/8)
	&&(tan(13*theta)<l_slope	&&	l_slope<tan(15*theta))	//tan(13*pi/8)<左肩<tan(15*pi/8)
	&&r_xshoulder<r_xhand	//右肩のx座標<右手のx距離
	&&l_xshoulder>l_xhand	//左肩のx座標>左手のx距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン３\n"<<std::endl;		

		pattern.push_back(3);//末尾に括弧内の数字を追加
	}



//パターン4ok	パターン3のつもりで作成したのだが4ができた。よくわかっていない。
  else if((tan(theta)<r_slope	&&	r_slope<tan(3*theta))	//tan(pi/8)<右肩<tan(3*pi/8)
	&&(tan(9*theta)<l_slope	&&	l_slope<tan(11*theta))	//tan(9*pi/8)<左肩<tan(11*pi/8)
	&&r_xshoulder<r_xhand	//右肩のx座標<右手のx距離
	&&l_xshoulder>l_xhand	//左肩のx座標>左手のx距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン４\n"<<std::endl;		

		pattern.push_back(4);//末尾に括弧内の数字を追加
	}



//パターン６
/*失敗している。２直線の角度がうまく取ることができていない。
tan(7*pi/8)<右肩<tan(9*pi/8)	
左肩<tan(5*pi/8)、tan(3*pi/8)<左肩	
左手左肘の直線の傾きと左肘左肩の直線の傾きが交わる角度が60度以上※角度要検討
右肩右肘直線と右肘右手直線の角度が60度以上//2パターン考えないといけないです
左手y座標>左肩のy座標
右肩と右手のz距離<30cm以下※要検討
左肩と左手のz距離<30cm以下※要検討
*/
/*
  double r_slope_se=(r_yshoulder-r_yelbow)/(r_xshoulder-r_xelbow);//右肩右肘の直線の傾き
  double l_slope_se=(l_yshoulder-l_yelbow)/(l_xshoulder-l_xelbow);//左肩左肘の直線の傾き
  double r_slope_eh=(r_yelbow-r_yhand)/(r_xelbow-r_xhand);//右肘右手の直線の傾き
  double l_slope_eh=(l_yelbow-l_yhand)/(l_xelbow-l_xhand);//左肘左手の直線の傾き
  
  std::cout<<"l_slope_se="<<l_slope_se<<std::endl;
  std::cout<<"l_slope_eh="<<l_slope_eh<<std::endl;
  std::cout<<"２直線の交点の角度は"<<(l_slope_eh-l_slope_se)/(1+l_slope_eh*l_slope_se)<<std::endl;

  if((tan(7*theta)<r_slope	&&	r_slope<tan(9*theta))	
//	&&(l_slope<tan(5*theta)||tan(3*theta)<l_slope)
//	&&line(r_slope_se,r_slope_eh,60)
	&&line(l_slope_se,l_slope_eh,60)//失敗している
//	&&l_yhand>l_yshoulder
//	&&fabs(r_zshoulder-r_zhand)<zspace
//	&&fabs(l_zshoulder-l_zhand)<zspace
	){
		std::cout<<"\nパターン６\n"<<std::endl;		
	}
*/

//パターン７
  else if((r_slope<tan(5*theta)||tan(3*theta)<r_slope)	//右肩<tan(5*pi/8)、tan(3*pi/8)<右肩
	&&(tan(-theta)<l_slope	&&	l_slope<tan(theta))	//tan(-pi/8)<左肩<tan(pi/8)
	&&fabs(l_yelbow-l_yshoulder)<150	//左肘のy座標-左肩のy座標<30cm以下
	&&fabs(r_xelbow-r_xshoulder)<150	//右肘のx座標-右肩のx座標<15cm※要検討
	){
		std::cout<<"\nパターン７\n"<<std::endl;		

		pattern.push_back(7);//末尾に括弧内の数字を追加
	}

//パターン８
  else if((tan(7*theta)<r_slope	&&	r_slope<tan(9*theta))	//tan(7*pi/8)<右肩<tan(9*pi/8)	
	&&(tan(11*theta)<l_slope||	l_slope<tan(13*theta))	//11*pi/8<左肩、左肩<13*pi/8
	&&fabs(r_yshoulder-r_yelbow)<150			//右肘のy座標-右肩のy座標<15cm以下
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン８\n"<<std::endl;		

		pattern.push_back(8);//末尾に括弧内の数字を追加
	}

//パターン９
//ok　パターン8と混合しやすい
  else if((tan(7*theta)<r_slope	&&	r_slope<tan(9*theta))	//tan(7*pi/8)<右肩<tan(9*pi/8)	
	&&fabs(r_yshoulder-r_yelbow)<150			//右肘のy座標-右肩のy座標<15cm以下
  	&&(tan(5*theta)<l_slope	&&	l_slope<tan(7*theta))	//tan(5*pi/8)<左肩<tan(7*pi/8)
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン９\n"<<std::endl;		

		pattern.push_back(9);//末尾に括弧内の数字を追加
	}

//パターン１０ok
  else if((tan(theta)<r_slope	&&	r_slope<tan(3*theta))	//tan(pi/8)<右肩<tan(3*pi/8)
	&&(tan(13*theta)<l_slope	&&	l_slope<tan(15*theta))	//tan(13*pi/8)<左肩<tan(15*pi/8)
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン１０\n"<<std::endl;		

		pattern.push_back(10);//末尾に括弧内の数字を追加
	}

//パターン１１
//やっていない

//パターン１２
  else if((r_slope<tan(5*theta)||tan(3*theta)<r_slope)	//右肩<tan(5*pi/8)、tan(3*pi/8)<右肩
	&&r_yshoulder<r_yhand	//右肩のy座標<右手のy距離
	&&(l_slope<tan(5*theta)||tan(3*theta)<l_slope)	//左肩<tan(5*pi/8)、tan(3*pi/8)<左肩
	&&l_yshoulder<l_yhand	//左肩の座標<左手のy距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン１２\n"<<std::endl;		

		pattern.push_back(12);//末尾に括弧内の数字を追加

	}


//パターン１３
  else if((tan(11*theta)<r_slope	||	r_slope<tan(13*theta))	//11*pi/8<右肩、右肩<13*pi/8	tan(11*pi/8)≒2.3 
	&&r_yshoulder>r_yhand	//右肩のy座標>右手のy距離
	&&(tan(13*theta)<l_slope	&&	l_slope<tan(15*theta))	//tan(13*pi/8)<左肩<tan(15*pi/8)
	&&l_xshoulder>l_xhand	//左肩のx座標>左手のx距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン１３\n"<<std::endl;		

		pattern.push_back(13);//末尾に括弧内の数字を追加
	}

//パターン１４
  else if((tan(theta)<r_slope	&&	r_slope<tan(3*theta))	//tan(pi/8)<右肩<tan(3*pi/8)
	&&r_xshoulder<r_xhand	//右肩のx座標<右手のx距離
	&&(tan(11*theta)<l_slope||	l_slope<tan(13*theta))	//11*pi/8<左肩、左肩<13*pi/8
	&&l_yshoulder>l_yhand	//左肩の座標>左手のy距離
	&&fabs(r_zshoulder-r_zhand)<zspace	//右肩と右手のz距離<30cm以下※要検討
	&&fabs(l_zshoulder-l_zhand)<zspace	//左肩と左手のz距離<30cm以下※要検討
	){
		std::cout<<"\nパターン１４\n"<<std::endl;

		pattern.push_back(14);//末尾に括弧内の数字を追加

	}

//パターン該当なし
  else 
	std::cout<<"該当なし"<<std::endl;

/////////////////////////////////////////////////パターン//////////////////////////////////////////////////

  std::cout<<"Size="<<pattern.size()<<std::endl;
  
  if(pattern.size()>19){
	pattern.erase(pattern.begin());
  }

  int i;
  if(pattern.size()>0){//pattern.size()>0でないとコアダンプ
	  for(i=pattern.size();i>=0;i--){
		std::cout<<"pattern["<<i<<"]="<<pattern[i]<<std::endl;
		}
  
  
	  int n=0;

	  for(i=0;i<20;i++){
		if(pattern[i]==100){
			n++;	
	  	}
	  }

	  int percent=80;
	  char check;
	  if(n/20*100>=percent){
		std::cout<<"y/n?"<<std::endl;
		std::cin>>check;
		if(check=='y'){
			std::cout<<"基本姿勢"<<std::endl;
		}
			
	  }
  }

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


