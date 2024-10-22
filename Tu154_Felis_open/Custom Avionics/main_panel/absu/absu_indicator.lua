-- this is the ABSU indicators

-- sources
defineProperty("absu_contr_pitch", globalPropertyf("sim/custom/absu/contr_pitch")) -- отклонение штока РА56 по тангажу
defineProperty("absu_contr_roll", globalPropertyf("sim/custom/absu/contr_roll")) -- отклонение штока РА56 по крену
defineProperty("absu_contr_yaw", globalPropertyf("sim/custom/absu/contr_yaw")) -- отклонение штока РА56 по направлению


defineProperty("int_pitch_trim", globalPropertyf("sim/custom/trimmers/int_pitch_trim")) -- положение триммера руля высоты
defineProperty("gear1_deflect", globalPropertyf("sim/flightmodel2/gear/tire_vertical_deflection_mtr[0]"))  -- vertical deflection of front gear

-- results
defineProperty("rudder_pos_ind", globalPropertyf("sim/custom/gauges/misc/rudder_pos_ind")) -- индикатор положения РН
defineProperty("aileron_pos_ind", globalPropertyf("sim/custom/gauges/misc/aileron_pos_ind")) -- индикатор положения элеронов
defineProperty("elevator_pos_ind", globalPropertyf("sim/custom/gauges/misc/elevator_pos_ind")) -- индикатор положения РВ


function update()

	set(rudder_pos_ind, get(absu_contr_yaw) / 0.4)
	set(aileron_pos_ind, get(absu_contr_roll) / 0.4)
	set(elevator_pos_ind, get(absu_contr_pitch) / 0.4)

	if get(gear1_deflect) > 0.01 and get(int_pitch_trim) < -0.5 then set(elevator_pos_ind, -get(absu_contr_pitch) / 0.4) end
	
	

end