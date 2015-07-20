// license:GPL-2.0+
// copyright-holders:Couriersud
/*
 * nld_74279.c
 *
 */

#include "nld_74279.h"

NETLIB_NAMESPACE_DEVICES_START()

nld_74279A::truthtable_t nld_74279A::m_ttbl;
nld_74279B::truthtable_t nld_74279B::m_ttbl;

#if 0
const char *nld_74279A::m_desc[] = {
		"S,R,PQ,PS,PR|Q",
		"0,0,X,X,X|1|22",
		"0,1,X,X,X|1|22",
		"1,0,X,X,X|0|15",
		"1,1,0,X,X|0|15",
		"1,1,1,X,X|1|22",
		""
};


const char *nld_74279B::m_desc[] = {
		"S1,S2,R,PQ,PS1,PS2,PR|Q",
		"0,X,0,X,X,X,X|1|22",
		"X,0,0,X,X,X,X|1|22",
		"0,X,1,X,X,X,X|1|22",
		"X,0,1,X,X,X,X|1|22",
		"1,1,0,X,X,X,X|0|15",
		"1,1,1,0,X,X,X|0|15",
		"1,1,1,1,X,X,X|1|22",
		""
};
#else
#if 1
const char *nld_74279A::m_desc[] = {
		"S,R,_Q|Q",
		"0,X,X|1|22",
		"1,0,X|0|27",
		"1,1,0|0|27", //15
		"1,1,1|1|22",
		""
};


const char *nld_74279B::m_desc[] = {
		"S1,S2,R,_Q|Q",
		"0,X,X,X|1|22",
		"X,0,X,X|1|22",
		"1,1,0,X|0|27",
		"1,1,1,0|0|27", // 15
		"1,1,1,1|1|22",
		""
};
#else
const char *nld_74279A::m_desc[] = {
		" S, R,_Q,_QR|Q,QR",
		" 0, 0, 0, 0 |1, 1|20,22",
		" 1, 0, 0, 0 |1, 1|20,22",
		" 0, 1, 0, 0 |1, 1|20,22",
		" 1, 1, 0, 0 |1, 1|20,22",
		" 0, 0, 1, 0 |1, 1|20,22",
		" 1, 0, 1, 0 |1, 1|20,22",
		" 0, 1, 1, 0 |1, 0|22,15",
		" 1, 1, 1, 0 |1, 0|22,15",
		" 0, 0, 0, 1 |1, 1|20,22",
		" 1, 0, 0, 1 |0, 1|15,22",
		" 0, 1, 0, 1 |1, 1|20,22",
		" 1, 1, 0, 1 |0, 1|15,22",
		" 0, 0, 1, 1 |1, 1|20,22",
		" 1, 0, 1, 1 |0, 1|15,22",
		" 0, 1, 1, 1 |1, 0|22,15",
		" 1, 1, 1, 1 |0, 0|13,15",
		""
};


const char *nld_74279B::m_desc[] = {
		"S1,S2,R,_Q,_QR|Q,QR",
		"0,0,0,0,0|1,1|20,22",
		"1,0,0,0,0|1,1|20,22",
		"0,1,0,0,0|1,1|20,22",
		"1,1,0,0,0|1,1|20,22",
		"0,0,1,0,0|1,1|20,22",
		"1,0,1,0,0|1,1|20,22",
		"0,1,1,0,0|1,1|20,22",
		"1,1,1,0,0|1,1|20,22",
		"0,0,0,1,0|1,1|20,22",
		"1,0,0,1,0|1,1|20,22",
		"0,1,0,1,0|1,1|20,22",
		"1,1,0,1,0|1,1|20,22",
		"0,0,1,1,0|1,0|22,15",
		"1,0,1,1,0|1,0|22,15",
		"0,1,1,1,0|1,0|22,15",
		"1,1,1,1,0|1,0|22,15",
		"0,0,0,0,1|1,1|20,22",
		"1,0,0,0,1|1,1|20,22",
		"0,1,0,0,1|1,1|20,22",
		"1,1,0,0,1|0,1|15,22",
		"0,0,1,0,1|1,1|20,22",
		"1,0,1,0,1|1,1|20,22",
		"0,1,1,0,1|1,1|20,22",
		"1,1,1,0,1|0,1|15,22",
		"0,0,0,1,1|1,1|20,22",
		"1,0,0,1,1|1,1|20,22",
		"0,1,0,1,1|1,1|20,22",
		"1,1,0,1,1|0,1|15,22",
		"0,0,1,1,1|1,0|22,15",
		"1,0,1,1,1|1,0|22,15",
		"0,1,1,1,1|1,0|22,15",
		"1,1,1,1,1|0,0|13,15",
		""
};

#endif
#endif


NETLIB_START(74279_dip)
{
	register_sub("1", m_1);
	register_sub("2", m_2);
	register_sub("3", m_3);
	register_sub("4", m_4);

	register_subalias("1", m_1.m_I[2]);  //R
	register_subalias("2", m_1.m_I[0]);
	register_subalias("3", m_1.m_I[1]);
	register_subalias("4", m_1.m_Q[0]);

	register_subalias("5", m_2.m_I[1]);  //R
	register_subalias("6", m_2.m_I[0]);
	register_subalias("7", m_2.m_Q[0]);

	register_subalias("9", m_3.m_Q[0]);
	register_subalias("10", m_3.m_I[2]); //R
	register_subalias("11", m_3.m_I[0]);
	register_subalias("12", m_3.m_I[1]);

	register_subalias("13", m_4.m_Q[0]);
	register_subalias("14", m_4.m_I[1]); //R
	register_subalias("15", m_4.m_I[0]);
}

NETLIB_UPDATE(74279_dip)
{
	/* only called during startup */
	m_1.update_dev();
	m_2.update_dev();
	m_3.update_dev();
	m_4.update_dev();
}

NETLIB_RESET(74279_dip)
{
	m_1.do_reset();
	m_2.do_reset();
	m_3.do_reset();
	m_4.do_reset();
}

NETLIB_NAMESPACE_DEVICES_END()
