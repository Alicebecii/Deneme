#include <iostream>
#include <string>

using namespace std;





double costCalculate(int type, int used_minutes, int used_sms, int used_mb, int add1, int add2, int add3) {
	int local_total_minutes_price = 0, local_total_sms_price = 0, local_total_internet_price = 0;
	int local_total_minutes = 0, local_total_sms = 0, local_total_internet = 0;
	int global_total_minutes_price = 0, global_total_sms_price = 0, global_total_internet_price = 0;
	int global_total_minutes = 0, global_total_sms = 0, global_total_internet = 0;
	int local_total = 0, global_total = 0;
	//calculations for Local phone Usage
	if (type == 1) {
		local_total_minutes = 250 + 250 * add1;
		if (used_minutes > local_total_minutes) {
			local_total_minutes_price = 30 * add1 + ((used_minutes - local_total_minutes) * 2);
		}
		else { local_total_minutes_price = 30 * add1; }
		local_total_sms = 1000 + 250 * add2;
		if (used_sms > local_total_sms) {
			local_total_sms_price = 30 * add2 + ((used_sms - local_total_sms) * 1);
		}
		else {
			local_total_sms_price = 30 * add2;
		}
		local_total_internet = 5120 + 1024 * add3;
		if (used_mb > local_total_internet) {
			local_total_internet_price = 30 * add3 + ((used_mb - local_total_internet) * 20.48);
		}

		else {
			local_total_internet_price = 30 * add3;
		}

		local_total = local_total_minutes_price + local_total_sms_price + local_total_internet_price + 120;
		return local_total;

	}
	//calculations for Global Usage
	else {
		global_total_minutes = 100 + 50 * add1;
		if (used_minutes > global_total_minutes) {
			global_total_minutes_price = 100 * add1 + ((used_minutes - global_total_minutes) * 15);
		}
		else { global_total_minutes_price = 100 * add1; }
		global_total_sms = 200 + 100 * add2;
		if (used_sms > global_total_sms) {
			global_total_sms_price = 100 * add2 + ((used_sms - global_total_sms) * 3);
		}
		else { global_total_sms_price = 100 * add2; }
		global_total_internet = 2048 + 1024 * add3;
		if (used_mb > global_total_internet) {
			global_total_internet_price = 100 * add3 + ((used_mb - global_total_internet) * 51.2);
		}
		else { global_total_internet_price = 100 * add3; }

		global_total = global_total_minutes_price + global_total_sms_price + global_total_internet_price + 300;
		return global_total;
	}

}
void displayResults(string country, double local_total, double global_total) {
	string m = "in Turkey";
	if (country == m) {
		cout << "Total cost of your phone usage " << country << " is " << local_total << " TL. ";
		if (local_total == 120) { cout << "You did not exceed your package." << endl; }
		else if (local_total != 120 and local_total < 240) { cout << "You exceeded your package." << endl; }
		else { cout << "You exceeded your package too much. We suggest you to change your package." << endl; }
	}
	else if (country == "Internationally") {
		cout << "Total cost of your phone usage " << country << " is " << global_total << " TL. ";

		if (global_total == 300) { cout << "You did not exceed your package." << endl; }
		else if (global_total < 600) { cout << "You exceeded your package." << endl; }
		else { cout << "You exceeded your package too much. We suggest you to change your package." << endl; }
	}

}


bool inputCheckmsg(int number1, string service) {
	bool status = true;
	if (number1 >= 0) { status = true; return status; }
	else {
		status = false; cout << "Number of " << service << " cannot be smaller than 0."; return status;
	}
}bool inputCheck(int number1) {

	bool status = true;
	if (number1 >= 0) { return true; }
	else { status = false; return false; }
}

int getInputs1(string service, string type, string country) {
	string m = "in Turkey";
	cout << "Please enter how many " << service << " you " << type << " this month " << country << ": ";
	int number = 0;
	cin >> number;
	return number;
}



bool getInputs(string service, string type, string country, int used_minutes, int used_sms, int used_mb)
{
	string m = "in Turkey";
	bool check = false;
	bool status = true;
	int number = 0;
	cout << "Please enter how many " << service << " you " << type << " this month " << country << ": ";
	cin >> number;
	if (service == "minutes") {
		used_minutes = number;

	}
	else if (service == "SMSs") { used_sms = number; }
	else { used_mb = number;  check = true; }
	if (inputCheck(number) == true) {

		if (check == true) {
			int local_total = 0, global_total = 0;
			int add1 = 0, add2 = 0, add3 = 0;
			cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
			cin >> add1 >> add2 >> add3;
			if (inputCheck(add1) == true and inputCheck(add2) == true and inputCheck(add3) == true) {
				if (country == m) {
					double local_total = costCalculate(1, used_minutes, used_sms, used_mb, add1, add2, add3);
					displayResults(m, local_total, global_total);
				}

				else {
					double global_total = costCalculate(2, used_minutes, used_sms, used_mb, add1, add2, add3);
					displayResults("Internationally", local_total, global_total);
					return true;
				}
			}
			else {
				if (add1 < 0) { service = "minutes"; }
				else if (add2 < 0) { service = "message"; }
				else { service = "internet"; }

				cout << "Number of additional " << service << " packages cannot be smaller than 0."; status = false; return status;
			}


		}



		return status;
	}
	else { cout << "Number of " << service << " cannot be smaller than 0."; status = false; return status; }
}



int main() {
	int number = 0;
	bool status = true;
	int used_minutes = 0, used_sms = 0, used_mb = 0;
	string m = "in Turkey";
	int deneme = getInputs1("minutes", "used", m);
	inputCheckmsg(deneme, "minutes");
	if (inputCheck(deneme) == true && status) {
		int deneme1 = getInputs1("SMSs", "sent", m);
		inputCheckmsg(deneme1, "SMSs");
		if (inputCheck(deneme1) == true && status) {
			bool a = getInputs("MBs", "used", m, deneme, deneme1, used_mb);

			if (a) {
				int deneme3 = getInputs1("minutes", "used", "Internationally");
				inputCheckmsg(deneme3, "minutes");

				if (inputCheck(deneme3) == true && status) {
					int deneme4 = getInputs1("SMSs", "sent", "Internationally");
					inputCheckmsg(deneme4, "SMSs");

					if (inputCheck(deneme4) == true && status) { getInputs("MBs", "used", "Internationally", deneme3, deneme4, used_mb); }

				}



			}
		}

	}
}