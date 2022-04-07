#include "BveAtsPlugin.h"

// Called when this plug-in is loaded
ATS_API void WINAPI Load(void)
{
    EXPORT_THIS_FUNCTION
}

// Called when this plug-in is unloaded
ATS_API void WINAPI Dispose(void)
{
    EXPORT_THIS_FUNCTION
}

// Returns the version numbers of ATS plug-in
ATS_API int WINAPI GetPluginVersion(void)
{
    EXPORT_THIS_FUNCTION
        return 0;
}

// Called when the train is loaded
ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC vehicleSpecification)
{
    EXPORT_THIS_FUNCTION
}

// Called when the game is started
ATS_API void WINAPI Initialize(int initialHandlePosition)
{
    EXPORT_THIS_FUNCTION
}

// Called every frame
ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE vehicleStatus, int* panelStatus, int* soundStatus)
{
    EXPORT_THIS_FUNCTION

        ATS_HANDLES ret;
    return ret;
}

// Called when the power is changed
ATS_API void WINAPI SetPower(int tractionControlHandlePosition)
{
    EXPORT_THIS_FUNCTION
}

// Called when the brake is changed
ATS_API void WINAPI SetBrake(int brakeControlHandlePosition)
{
    EXPORT_THIS_FUNCTION
}

// Called when the reverser is changed
ATS_API void WINAPI SetReverser(int reverserHandlePosition)
{
    EXPORT_THIS_FUNCTION
}

// Called when any ATS key is pressed
ATS_API void WINAPI KeyDown(int key)
{
    EXPORT_THIS_FUNCTION
}

// Called when any ATS key is released
ATS_API void WINAPI KeyUp(int key)
{
    EXPORT_THIS_FUNCTION
}

// Called when the horn is used
ATS_API void WINAPI HornBlow(int hornType)
{
    EXPORT_THIS_FUNCTION
}

// Called when the door is opened
ATS_API void WINAPI DoorOpen(void)
{
    EXPORT_THIS_FUNCTION
}

// Called when the door is closed
ATS_API void WINAPI DoorClose(void)
{
    EXPORT_THIS_FUNCTION
}

// Called when current signal is changed
ATS_API void WINAPI SetSignal(int signal)
{
    EXPORT_THIS_FUNCTION
}

// Called when the beacon data is received
ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA recievedBeaconData)
{
    EXPORT_THIS_FUNCTION
}
