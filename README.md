# Bài tập — Khóa hè Embedded C 2026

Repo **gốc (upstream)** chứa đề bài và khung nộp bài của khóa học — Machine Learning & IoT Lab, HCMUT.

> 📅 21/6 – 30/8/2026 · Chủ nhật

---

## 🚀 Hướng dẫn cho học viên (luồng Fork)

### Bước 1 — Fork repo gốc
Vào repo này trên GitHub, bấm nút **Fork** (góc trên bên phải) → GitHub tạo một **repo cá nhân** của bạn (đây là remote `origin`).

### Bước 2 — Clone fork của bạn về máy
```bash
git clone https://github.com/<ten-cua-ban>/mliot-embeddedc-2026-hw.git
cd mliot-embeddedc-2026-hw
```

### Bước 3 — Thêm remote `upstream` trỏ về repo gốc
```bash
git remote add upstream https://github.com/mliotlab/mliot-embeddedc-2026-hw.git
git remote -v          # kiem tra: co origin (fork cua ban) va upstream (repo goc)
```

> **Hai remote:** `origin` = fork cá nhân của bạn · `upstream` = repo gốc của Lab.

---

## 🔄 Mỗi buổi học

### Lấy đề mới (cập nhật từ repo gốc)
Đề bài của các buổi được thêm dần vào repo gốc. Trước mỗi buổi, đồng bộ:
```bash
git pull upstream main
```

### Làm bài & nộp
Truy cập vào thư mục tuần tương ứng (`weekXX/`), đọc đề bài và hướng dẫn trong file `REQUIREMENT.md`, hoàn thành bài tập theo file mẫu `main.c` có sẵn, rồi đẩy lên fork cá nhân:
```bash
git add week01/
git commit -m "week01: hoan thanh bai tap buoi 1"
git push origin main
```

### Nộp bài cho mentor
- Cách 1 (mặc định): gửi **link repo cá nhân (fork)** của bạn trên Discord để mentor vào check.
- Cách 2 (nếu mentor yêu cầu): tạo **Pull Request** từ fork của bạn về repo gốc để mentor review.

---

## 📝 Quy ước nộp bài

- Đặt bài làm vào **đúng thư mục tuần** (`weekXX/`).
- Định dạng: file `.c`; đặt tên rõ ràng, ví dụ `buoi01_nguyenvana.c`.
- Commit message rõ ràng: `week01: hoan thanh bai tap buoi 1`.
- **Không commit** dữ liệu lớn / file nặng.

---

## ℹ️ Ghi chú

- Nếu `git pull upstream main` báo xung đột (conflict): thường do bạn sửa cùng file với repo gốc — giữ phần bài làm của bạn trong `weekXX/` và giải quyết conflict theo hướng dẫn của mentor.
- Repo gốc nên để **Public** để học viên fork được.

---

*Machine Learning & IoT Lab — Khoa Điện–Điện tử, Đại học Bách khoa - ĐHQG TP.HCM*
