#include <devtest.h>

void rtc_test() {
  DEV_TIMER_RTC_T rtc;
  int sec = 1;
  while (1) {
    while(io_read(DEV_TIMER_UPTIME).us / 1000000 < sec) {
    };
    // printf("%ld\n", io_read(DEV_TIMER_UPTIME).us);
    rtc = io_read(DEV_TIMER_RTC);
    printf("%d-%d-%d %02d:%02d:%02d GMT (", rtc.year, rtc.month, rtc.day, rtc.hour, rtc.minute, rtc.second);
    if (sec == 1) {
      printf("%d second).\n", sec);
    } else {
      printf("%d seconds).\n", sec);
    }
    sec ++;
  }
}

int main(const char* argv){
  ioe_init();
  rtc_test();
  return 0;
}
