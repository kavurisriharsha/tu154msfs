-- this is TCAS root
size = {2048, 2048}


components = {
	
	tcas_panel {
		position = {0, 0, size[1], size[2]},
	},

	so72_panel {
		position = {23, 1046, 440, 167},
	},
	
	tcas_logic {
		position = {0, 0, size[1], size[2]},
	},
	
	tcas_gau {
		position = {11, 11, 482, 530},
	},

	tcas_gau {
		position = {518, 11, 482, 530},
		var_on = globalPropertyi("sim/custom/switchers/ovhd/var_right"),  -- оерхед. вар лев
		bus27_volt = globalPropertyf("sim/custom/elec/bus27_volt_right"), -- напряжение сети 27
		bus115_volt = globalPropertyf("sim/custom/elec/bus115_3_volt"), -- напряжение на сети 115в
		vsi_brt = globalPropertyf("sim/custom/gauges/vsi/vsi_brt_right"),  -- яркость
		vvi_int = globalPropertyf("sim/custom/gauges/vvi_right"), -- VVI
		vvi_fail = globalPropertyi("sim/operation/failures/rel_cop_vvi"), -- fail
	},
	
	
	

}