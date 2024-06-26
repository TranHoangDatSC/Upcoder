#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lớp cơ bản đại diện cho một sản phẩm - Product
class Product
{
protected:
    /* Các thuộc tính của Product */

    string id;  // Mã sản pharm
    string name;    // Tên sản phẩm
    double origin_price;    // Giá gốc của sản phẩm
    int numbers;    // Số lượng sản phẩm

public:
    /* Hai hàm khởi tạo */
    Product() : id(""), name(""), origin_price(0.0), numbers(0) {}

    Product(string _id, string _name, double _origin_price, int _numbers) :
        id(_id), name(_name), origin_price(_origin_price), numbers(_numbers) {}

    Product(const Product& product)
    {
        id = product.id;
        name = product.name;
        origin_price = product.origin_price;
        numbers = product.numbers;
    }

    /* Hàm hủy */
    virtual ~Product() {}

    /* 8 hàm Get Set cho các thuộc tính */
    string getId() { return id; }
    string getName() { return name; }
    double getOP() { return origin_price; }
    int getNumbers() const { return numbers; }

    void setId(string _id) { id = _id; }
    void setName(string _name) { name = _name; }
    void setOP(double _origin_price) { origin_price = _origin_price; }
    void setNumbers(int _numbers) { numbers = _numbers; }
    /**/

    virtual double Price_sell() const = 0;  // Phương thức ảo tính giá bán của sản phẩm

    virtual double Profit() const = 0;      // Phương thức ảo tính lợi nhuận từ sản phẩm

    virtual int Numbers_product() const = 0;   // Phương thức ảo trả về số lượng sản phẩm

    // Tính vốn đầu tư (giá gốc * số lượng)
    double Capital() const
    {
        return origin_price * numbers;
    }

    // Toán tử xuất << cho việc in ra thông tin sản phẩm
    friend ostream& operator<<(ostream& os, const Product& product)
    {
        os << "Id: " << product.id << " | Name: " << product.name << " | Origin Price: "
            << product.origin_price << " $ | Numbers: " << product.numbers;
        return os;
    }
};

// Lớp Sản phẩm nhập khẩu, kế thừa từ lớp Product
class Imported : public Product
{
private:
    double tax; // Thuế nhập khẩu
    string nation;  // Quốc gia xuất xứ

public:
    // 2 Hàm khởi tạo
    Imported(string _id = "", string _name = "", double _origin_price = 0.0, int _numbers = 0, double _tax = 0.0, string _nation = "XXXXX") :
        Product(_id, _name, _origin_price, _numbers), tax(_tax), nation(_nation) {}

    Imported(const Imported& product) : Product(product)
    {
        tax = product.tax;
        nation = product.nation;
    }

    // 4 hàm Get Set cho các thuộc tính
    double getTax() { return tax; }
    string getNation() { return nation; }

    void setTax(double _tax) { tax = _tax; }
    void setNation(string _nation) { nation = _nation; }

    // Phưong thức tính giá bán
    double Price_sell() const override
    {
        return origin_price * (1 + tax);
    }

    // Phương thức tính lợi nhuận
    double Profit() const override {
        return (Price_sell() - origin_price) * numbers;
    }

    // Phương thức trả về số lượng sản phẩm
    int Numbers_product() const override {
        return numbers;
    }

    // Nạp chồng toán tử nhập >> cho việc nhập thông tin sản phẩm nhập khẩu 
    friend istream& operator>>(istream& is, Imported& product) {
        is >> product.id >> product.name >> product.origin_price >> product.numbers;
        is >> product.tax >> product.nation;
        return is;
    }

    // Nạp chồng toán tử xuất << cho việc xuất thông tin sản phẩm nhập khẩu
    friend ostream& operator<<(ostream& os, const Imported& product) {
        os << "ImportedProducts:\n";
        os << static_cast<const Product&>(product) << " | With Tax: " << product.Price_sell() * product.Numbers_product()
            << " $ | Made in: " << product.nation;
        return os;
    }
};

// Lớp Sản phẩm nội địa, kế thừa từ lớp Product
class Local : public Product {
private:
    double promotion;   // ưu đãi

public:
    // 2 Hàm khởi tạo
    Local(string _id = "", string _name = "", double _origin_price = 0.0,
        int _numbers = 0, double _promotion = 0.0) :
        Product(_id, _name, _origin_price, _numbers), promotion(_promotion) {}

    Local(const Local& product) : Product(product)
    {
        promotion = product.promotion;
    }

    // 2 hàm Get Set thuộc tính
    double getPromotion() { return promotion; }
    void setPromotion(double _promotion) { promotion = _promotion; }

    // Phương thức tính giá bán
    double Price_sell() const override
    {
        return origin_price * (1 - promotion);
    }

    // Ph??ng th?c tính l?i nhu?n
    double Profit() const override
    {
        return (Price_sell() - origin_price) * numbers;
    }

    // Ph??ng th?c tr? v? s? l??ng s?n ph?m
    int Numbers_product() const override
    {
        return numbers;
    }

    // N?p ch?ng toán t? >> cho vi?c nh?p thông tin s?n ph?m n?i ??a
    friend istream& operator>>(istream& is, Local& product)
    {
        is >> product.id >> product.name >> product.origin_price >> product.numbers;
        is >> product.promotion;
        return is;
    }

    // N?p ch?ng toán t? << cho vi?c xu?t thông tin s?n ph?m n?i ??a
    friend ostream& operator<<(ostream& os, const Local& product)
    {
        os << "LocalProducts:\n";
        os << static_cast<const Product&>(product) << " | With Promo: " << product.Price_sell() * product.Numbers_product() << " $";
        return os;
    }
};

int main() {
    int num_products;
    cin >> num_products;    // Nh?p s? l??ng s?n ph?m

    vector<Imported> imported_products; // Vector l?u tr? các s?n ph?m nh?p kh?u
    vector<Local> local_products;    // Vector l?u tr? các s?n ph?m n?i ??a

    string type;    // Ki?u s?n ph?m nh?p kh?u / n?i ??a

    // Duy?t qua t?ng s?n ph?m ?? nh?p thông tin và thêm vào vector t??ng ?ng
    for (int i = 0; i < num_products; ++i)
    {
        cin >> type;    // Nh?p lo?i s?n ph?m
        if (type == "imported") // N?u là s?n ph?m nh?p kh?u
        {
            Imported product;
            cin >> product;     // Nh?p thông tin s?n ph?m 
            imported_products.push_back(product);   // Thêm vào vector s?n ph?m nh?p kh?u
        }
        else if (type == "local") // N?u là s?n ph?m n?i ??a
        {
            Local product;
            cin >> product;     // Nh?p thông tin s?n ph?m
            local_products.push_back(product);  // Thêm vào vector s?n ph?m n?i ??a
        }
    }

    double total_profit = 0.0;      // T?ng l?i nhu?n
    double total_capital = 0.0;     // T?ng ti?n v?n
    double total_turnover = 0.0;    // T?ng doanh s? bán hàng

    // In thông tin các s?n ph?m nh?p kh?u
    for (const auto& product : imported_products)
    {
        cout << product << endl;
    }

    // In thông tin các s?n ph?m n?i ??a
    for (const auto& product : local_products)
    {
        cout << product << endl;
    }

    // Duy?t qua các s?n ph?m nh?p kh?u ?? tính t?ng l?i nhu?n, ti?n v?n và doanh s? bán hàng
    for (const auto& product : imported_products)
    {
        total_profit += product.Profit();   // Tính l?i nhu?n t? s?n ph?m nh?p kh?u
        total_capital += product.Capital(); // Tính v?n t? s?n ph?m nh?p kh?u
        total_turnover += product.Price_sell() * product.getNumbers();  // Tính doanh s? bán hàng t? s?n ph?m nh?p kh?u
    }

    // Duy?t qua các s?n ph?m n?i ??a ?? tính t?ng l?i nhu?n, ti?n v?n và doanh s? bán hàng
    for (const auto& product : local_products)
    {
        total_profit += product.Profit();   // Tính lợi nhuận từ sản phẩm nội địa
        total_capital += product.Capital(); // Tính vốn từ sản phẩm nội địa
        total_turnover += product.Price_sell() * product.getNumbers();  // Tính doanh số bán hàng từ sản phẩm nội địa
    }

    // In tổng lợi nhuận, tiền vốn và doanh số bán hàng ra màn hình
    cout << "\nProfit : " << total_profit << " $\nCapital: " << total_capital;
    cout << " $\nTurnover: " << total_turnover << " $";

    return 0;
}
