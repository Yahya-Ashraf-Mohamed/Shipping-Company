//#pragma once
////=================================================== EVENTS =================================================
//
//	//takes cargo id and type then returns cargo pointer
//Cargo* MarsStation::getCargo(int id, TYP type)
//{
//	Cargo* pCargo;
//	Cargo* reqCargo = nullptr;       //requested cargo
//	switch (type)
//	{
//	case VIP:
//		for (int i = 0; i < VIP_Cargo_count; i++)
//		{
//			VIP_Cargo.dequeue(pCargo);
//			if (pCargo->get_cargo_id() == id)
//				reqCargo = pCargo;
//			VIP_Cargo.enqueue(pCargo);
//		}
//		break;
//
//
//	case SPECIAL:
//		for (int i = 0; i < Special_Cargo_count; i++)
//		{
//			Special_Cargo.dequeue(pCargo);
//			if (pCargo->get_cargo_id() == id)
//				reqCargo = pCargo;
//			Special_Cargo.enqueue(pCargo);
//		}
//		break;
//
//
//	case NORMAL:
//		for (int i = 0; i < Normal_Cargo_count; i++)
//		{
//			Normal_Cargo.dequeue(pCargo);
//			if (pCargo->get_cargo_id() == id)
//				reqCargo = pCargo;
//			Normal_Cargo.enqueue(pCargo);
//		}
//		break;
//	}
//
//	return reqCargo;
//}
//
////excutes events when their time comes   (not complete yet it will also include loading)
//void MarsStation::ExcuteEvent(int time, int day)
//{
//	Cargo* pCargo;
//
//	//VIP cargo loop
//	for (int i = 0; i < VIP_Cargo_count; i++)
//	{
//		VIP_Cargo.dequeue(pCargo);
//		//implementation related to load
//		VIP_Cargo.enqueue(pCargo);
//	}
//
//	//special cargo loop
//	for (int i = 0; i < Special_Cargo_count; i++)
//	{
//		Special_Cargo.dequeue(pCargo);
//		//implementation related to load
//		Special_Cargo.enqueue(pCargo);
//	}
//
//	//normal cargo loop
//	for (int i = 0; i < Normal_Cargo_count; i++)
//	{
//		Normal_Cargo.dequeue(pCargo);
//		//implementation related to load
//		Normal_Cargo.enqueue(pCargo);
//	}
//}
//
////Add Cargo to Cargo Queue depending on it's type
//void MarsStation::AddCargo(Cargo* pCargo, TYP CargoType)
//{
//	switch (CargoType)
//	{
//	case VIP:
//		VIP_Cargo.enqueue(pCargo);
//		VIP_Cargo_count++;
//		break;
//	case SPECIAL:
//		Special_Cargo.enqueue(pCargo);
//		Special_Cargo_count++;
//		break;
//	case NORMAL:
//		Normal_Cargo.enqueue(pCargo);
//		Normal_Cargo_count++;
//		break;
//	}
//}
//
////Promote normal cargo to VIP cargoes and returns pointer to the promoted Cargo
//void MarsStation::PromoteCargo(Cargo* pCargo)
//{
//	Normal_Cargo.dequeue(pCargo);
//	Normal_Cargo_count--;
//	VIP_Cargo.enqueue(pCargo);
//	VIP_Cargo_count++;
//}
//
////Cancel Cargo
//void MarsStation::CancelCargo(Cargo* pCargo)
//{
//	Normal_Cargo.dequeue(pCargo);
//	Normal_Cargo_count--;
//	delete pCargo;
//}