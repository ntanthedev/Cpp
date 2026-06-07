import asyncio
from pathlib import Path
from crawl4ai import *

async def main():
    urls = [
        "https://giangday.vst.edu.vn/lab/course/CPP?index=2&chapter=basic",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=3&chapter=operators",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=4&chapter=ifelse",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=5&chapter=loop",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=6&chapter=array",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=7&chapter=pointer",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=8&chapter=func",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=9&chapter=struct",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=10&chapter=oop",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=11&chapter=opertator-overload",
        "https://giangday.vst.edu.vn/lab/course/CPP?index=12&chapter=inherits",
    ]
    
    async with AsyncWebCrawler() as crawler:
        all_markdown = ""
        for url in urls:
            result = await crawler.arun(url=url)
            if result.markdown:
                all_markdown += result.markdown + "\n\n---\n\n"
            else:
                print(f"No content found for {url}")
        
        if all_markdown:
            output_path = Path(__file__).with_name("a.md")
            output_path.write_text(all_markdown, encoding="utf-8")
            print("Saved to a.md")

if __name__ == "__main__":
    asyncio.run(main())