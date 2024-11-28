class ParameterManager:
    def __init__(self):
        # Common parameters
        self.__lrl = 60.0  # single (float)
        self.__url = 120  # single (float)
        self.__msr = 120  # single (float)
        self.__fixed_av_delay = 150  # single (float)
        self.__atrial_amplitude = 5.0  # single (float)
        self.__ventricular_amplitude = 5.0  # single (float)
        self.__atrial_pulse_width = 1.0  # single (float)
        self.__ventricular_pulse_width = 1.0  # single (float)
        self.__atrial_sensitivity = 0.1  # single (float)
        self.__ventricular_sensitivity = 0.1  # single (float)
        self.__arp = 250  # single (float)
        self.__vrp = 320  # single (float)
        self.__pvarp = 250  # uint16
        self.__hysteresis = 0  # uint8
        self.__rate_smoothing = 0  # uint8
        self.__activity_threshold = 1.6  # single (float)
        self.__reaction_time = 30.0  # single (float)
        self.__response_factor = 8  # single (float)
        self.__recovery_time = 300.0  # single (float), sec = 5 min

    # Getters for common parameters
    def getLowerRateLimit(self):
        return self.__lrl

    def getUpperRateLimit(self):
        return self.__url

    def getMaximumSensorRate(self):
        return self.__msr

    def getFixedAVDelay(self):
        return self.__fixed_av_delay

    def getAtrialAmplitude(self):
        return self.__atrial_amplitude if self.__atrial_amplitude != 0 else 0.0

    def getVentricularAmplitude(self):
        return self.__ventricular_amplitude if self.__ventricular_amplitude != 0 else 0.0

    def getAtrialPulseWidth(self):
        return self.__atrial_pulse_width

    def getVentricularPulseWidth(self):
        return self.__ventricular_pulse_width

    def getAtrialSensitivity(self):
        return self.__atrial_sensitivity

    def getVentricularSensitivity(self):
        return self.__ventricular_sensitivity

    def getARP(self):
        return self.__arp

    def getVRP(self):
        return self.__vrp

    def getPVARP(self):
        return self.__pvarp

    def getHysteresis(self):
        return self.__hysteresis if self.__hysteresis != 0 else 0

    def getRateSmoothing(self):
        return self.__rate_smoothing

    def getActivityThreshold(self):
        return self.__activity_threshold

    def getReactionTime(self):
        return self.__reaction_time

    def getResponseFactor(self):
        return self.__response_factor

    def getRecoveryTime(self):
        return self.__recovery_time / 60.0

    # Setters for common parameters
    def setLowerRateLimit(self, val):
        if self.__is_num(val):
            num = float(val)
            if 30.0 <= num <= 175.0:
                self.__lrl = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setUpperRateLimit(self, val):
        if self.__is_num(val):
            num = float(val)
            if 50.0 <= num <= 175.0 and num >= self.__lrl:
                self.__url = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setMaximumSensorRate(self, val):
        if self.__is_num(val):
            num = float(val)
            if 50.0 <= num <= 175.0 and num >= self.__lrl:
                self.__msr = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setFixedAVDelay(self, val):
        if self.__is_num(val):
            if 70.0 <= float(val) <= 300.0:
                self.__fixed_av_delay = float(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setAtrialAmplitude(self, val):
        if str(val).casefold() == 'off'.casefold():
            self.__atrial_amplitude = 0.0
            return
        if self.__is_num(val):
            num = round(float(val), 1)
            if 0.1 <= num <= 5.0:
                self.__atrial_amplitude = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setVentricularAmplitude(self, val):
        if str(val).casefold() == 'off'.casefold():
            self.__ventricular_amplitude = 0.0
            return
        if self.__is_num(val):
            num = round(float(val), 1)
            if 0.1 <= num <= 5.0:
                self.__ventricular_amplitude = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setAtrialPulseWidth(self, val):
        if self.__is_num(val):
            if 1.0 <= float(val) <= 30.0:
                self.__atrial_pulse_width = float(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setVentricularPulseWidth(self, val):
        if self.__is_num(val):
            if 1.0 <= float(val) <= 30.0:
                self.__ventricular_pulse_width = float(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setAtrialSensitivity(self, val):
        if self.__is_num(val):
            if 0.0 <= float(val) <= 5.0:
                self.__atrial_sensitivity = round(float(val), 1)
            else:
                raise IndexError
        else:
            raise TypeError

    def setVentricularSensitivity(self, val):
        if self.__is_num(val):
            if 0.0 <= float(val) <= 5.0:
                self.__ventricular_sensitivity = round(float(val), 1)
            else:
                raise IndexError
        else:
            raise TypeError

    def setARP(self, val):
        if self.__is_num(val):
            if 150.0 <= float(val) <= 500.0:
                self.__arp = float(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setVRP(self, val):
        if self.__is_num(val):
            if 150.0 <= float(val) <= 500.0:
                self.__vrp = float(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setPVARP(self, val):
        if self.__is_num(val):
            if 150 <= int(val) <= 500:
                self.__pvarp = int(val)
            else:
                raise IndexError
        else:
            raise TypeError

    def setHysteresis(self, val):
        if str(val).casefold() == 'off'.casefold():
            self.__hysteresis = 0
            return
        if self.__is_num(val):
            num = int(float(val))
            if 0 <= num <= 175:
                self.__hysteresis = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setRateSmoothing(self, val):
        if self.__is_num(val):
            num = int(val)
            if 0 <= num <= 25:
                self.__rate_smoothing = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setActivityThreshold(self, val):
        if self.__is_num(val):
            self.__activity_threshold = float(val)
        else:
            raise TypeError

    def setReactionTime(self, val):
        if self.__is_num(val):
            num = float(val)
            if 10.0 <= num <= 50.0:
                self.__reaction_time = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setResponseFactor(self, val):
        if self.__is_num(val):
            num = float(val)
            if 1.0 <= num <= 16.0:
                self.__response_factor = num
            else:
                raise IndexError
        else:
            raise TypeError

    def setRecoveryTime(self, val):
        if self.__is_num(val):
            num = float(val)
            if 1.0 <= num <= 16.0:
                self.__recovery_time = num * 60
            else:
                raise IndexError
        else:
            raise TypeError

    def __is_num(self, s):
        try:
            float(s)
        except ValueError:
            return False
        else:
            return True
