
#include "signaling.h"
#include "utility.h"

#include "render_encoder.h"

int main() {
  rigel::InitializeLogger();
  rigel::InitializeSSL();

  {
    new rigel::RenderEncoder();
  }
  {
    std::unique_ptr<rigel::SignalingContext> context(
        new rigel::SignalingContext("127.0.0.1", "8080", "/wssrv"));
    context->Run();
  }
  rigel::CleanupSSL();
  return 0;
}
