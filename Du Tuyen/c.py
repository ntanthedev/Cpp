# translate_txt_to_md.py
# Mục tiêu: đọc file .txt, chia nhỏ nếu dài, gửi vào LM Studio model text-only, ghi ra .md

import lmstudio as lms
from pathlib import Path
import textwrap

# ==== cấu hình ====
IN_TXT  = r"D:\ntan's code\Cpp\Du Tuyen\a.txt"     # đường dẫn file đề ở dạng text
OUT_MD  = r"D:\ntan's code\Cpp\Du Tuyen\out_vi.md" # file kết quả markdown
MODELID = "openai/gpt-oss-20b"                    # hoặc model text-only khác bạn đang mở trong LM Studio

SYSTEM_PROMPT = (
    "Bạn là dịch giả song ngữ chuyên nghiệp. "
    "Hãy dịch chính xác nội dung tiếng Anh sang tiếng Việt, "
    "giữ nguyên bố cục (tiêu đề, danh sách, code), không thêm bình luận."
)

# Chia nhỏ để tránh vượt context; bạn có thể tăng/giảm tùy model đang chạy
MAX_CHARS_PER_CHUNK = 6000

def main():
    src = Path(IN_TXT)
    if not src.exists():
        raise SystemExit(f"Không tìm thấy file: {src}")

    text = src.read_text(encoding="utf-8", errors="ignore").strip()
    if not text:
        raise SystemExit("File trống.")

    llm  = lms.llm(MODELID)
    chat = lms.Chat(SYSTEM_PROMPT)
    chat.add_user_message(
        f"Hãy dịch nội dung đề bài sau sang tiếng Việt, giữ nguyên cấu trúc:\n\n{text}"
    )
    vi = llm.respond(chat)
    chat.add_assistant_response(vi)  # giữ ngữ cảnh giữa các đoạn (tùy)
    # out_sections.append(vi)

    Path(OUT_MD).write_text("\n\n---\n\n".join(vi), encoding="utf-8")
    print(f"[xong] Đã ghi: {OUT_MD}")

if __name__ == "__main__":
    main()
