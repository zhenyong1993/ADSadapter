set(SOURCES
  AdsDevice.cpp
  AdsDef.cpp
  Log.cpp
  Sockets.cpp
  Frame.cpp
  standalone/AdsLib.cpp
  standalone/AmsConnection.cpp
  standalone/AmsNetId.cpp
  standalone/AmsPort.cpp
  standalone/AmsRouter.cpp
  standalone/NotificationDispatcher.cpp
)

add_library(ads ${SOURCES})
add_library(ADSadapter SHARED ${SOURCES} ADSadapter.cpp)

target_include_directories(ads PUBLIC .)
target_include_directories(ADSadapter PUBLIC .)

target_link_libraries(ads PUBLIC Threads::Threads)
