#include "CLOCK.h"

const ClockConfigType clockConfig = {
	.SmClkSource    = CLOCK_SMCLK_SOURCE_DEFAULT,
	.SmClkDivider   = CLOCK_SMCLK_DIVIDE_DEFAULT,
	.MclkSource     = CLOCK_MCLK_SOURCE_DEFAULT,
	.MclkDivider    = CLOCK_SMCLK_DIVIDE_DEFAULT,
	.AclkDivider    = CLOCK_ACLK_DIVIDE_DEFAULT,
	.PredefinedFreq = CLOCK_PREDEFINED_FREQ_1MHZ,
	.DcoConfig = {
		.DcoResistor  	 = CLOCK_DCO_RESISTOR_DEFAULT,
		.FrequencyRange  = CLOCK_DCO_FREQUENCY_RANGE_DEFAULT,
		.Modulator       = CLOCK_DCO_MODULATOR_DEFAULT,
		.FrequencySelect = CLOCK_DCO_FREQUENCY_SELECT_DEFAULT
	},
	.Xt2Config = {
		.Enabled = CLOCK_XT2_ENABLED_DEFAULT,
		.RangeSelect = CLOCK_XT2_RANGE_DEFAULT
	},
	.Xt1Config = {
		.Mode = CLOCK_XT1_MODE_DEFAULT,
		.ClockSelect = CLOCK_XT1_CLOCK_SELECT_DEFAULT,
		.Capacitor = CLOCK_XT1_CAPACITOR_DEFAULT
	}
};