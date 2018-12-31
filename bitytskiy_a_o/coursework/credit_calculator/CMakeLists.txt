

set(credit_SRCS
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
resultwindow.cpp
resultwindow.h
resultwindow.ui
dosrochpogash.cpp
dosrochpogash.h
dosrochpogash.ui
)

add_executable(CreditCalculator ${credit_SRCS})
target_link_libraries(CreditCalculator Qt5::Widgets)
include_directories(/dll)
