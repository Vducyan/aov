#import "LIB/Esp/ImGuiDrawView.h"
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>
#include <mach/mach.h>
#include <math.h> // Thêm dòng này
#import <Foundation/Foundation.h>
#import "Include.h"
#include <vector>
#include <thread>
#include "hook/hook.h"
#include "RequireESP/Vector3.h"
#include "RequireESP/Vector2.h"
#include "RequireESP/Quaternion.h"
#include "RequireESP/Monostring.h"
#include "RequireESP/Esp.h"
#import "JRMemory.framework/Headers/MemScan.h"
#import <UIKit/UIKit.h>




UIWindow *mainWindow;
UIButton *menuView;
@interface ImGuiDrawView () <MTKViewDelegate>
@property (nonatomic, strong) id <MTLDevice> device;
@property (nonatomic, strong) id <MTLCommandQueue> commandQueue;


- (void)ghost;
- (void)removeGhost; 
- (void)switchIsChanged:(UISwitch *)SW1;
- (void)text;
@end

@implementation ImGuiDrawView
static bool MenDeal = true;

void aimawmFunction() {
    static dispatch_once_t onceToken;
      dispatch_async(dispatch_get_global_queue(0, 0), ^{
  JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
    AddrRange range = {0x100000000, 0x200000000};
    
    uint64_t search = 31101603021;
    engine.JRScanMemory(range, &search, JR_Search_Type_ULong);
    
    std::vector<void*> results = engine.getAllResults();
    uint32_t modify = 2139095040;
    
    for(size_t i = 0; i < results.size(); i++) {
        uint64_t addr1 = (uint64_t)results[i];
        uint64_t dizhi0 = addr1 + 8;
        engine.JRWriteMemory(dizhi0, &modify, JR_Search_Type_UInt);
    }
});
       std::this_thread::sleep_for(std::chrono::seconds(7)); // Sleep for 5 seconds
  }





void aimscopeFunction() {
    static dispatch_once_t onceToken;
      dispatch_async(dispatch_get_global_queue(0, 0), ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000, 0x160000000};
        uint32_t search = 1075000115;
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        uint32_t search1 = 3;
        engine.JRNearBySearch(0x100, &search1, JR_Search_Type_UInt);
        uint32_t search2 = 1075000115;
        engine.JRScanMemory(range, &search2, JR_Search_Type_UInt);
        vector<void *> results = engine.getAllResults();
        uint32_t modify = -5;
        for (int i = 0; i < results.size(); i++) {
          engine.JRWriteMemory((unsigned long long)(results[i]), &modify,
                               JR_Search_Type_UInt);
        }
});
       std::this_thread::sleep_for(std::chrono::seconds(7)); // Sleep for 5 seconds
  }


void aim180Function() {
    static dispatch_once_t onceToken;
      dispatch_async(dispatch_get_global_queue(0, 0), ^{
JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
         AddrRange range = (AddrRange){0x100000000, 0x160000000};
         uint32_t search = 1057048494;
         engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
         uint32_t search1 = 1054951342;
         engine.JRNearBySearch(0x100, &search1, JR_Search_Type_UInt);
         uint32_t search2 = 1053273620;
         engine.JRNearBySearch(0x100, &search2, JR_Search_Type_UInt);
         vector<void *> results = engine.getAllResults();
         uint32_t modify = -2000;
         for (int i = 0; i < results.size(); i++) {
           engine.JRWriteMemory((unsigned long long)(results[i]), &modify,
                                JR_Search_Type_UInt);
        }
});
       std::this_thread::sleep_for(std::chrono::seconds(7)); // Sleep for 5 seconds
  }

void LockfireFunction() {
    static dispatch_once_t onceToken;
      dispatch_async(dispatch_get_global_queue(0, 0), ^{
     JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x160000000};
        float search = 0.15;
        engine.JRScanMemory(range, &search, JR_Search_Type_Float);
        float search1 = 1.5;
        engine.JRNearBySearch(0x60,&search1,JR_Search_Type_Float);
        float search2 = 1.5;
        engine.JRScanMemory(range, &search2, JR_Search_Type_Float);
        vector<void*>results = engine.getAllResults();
        float modify = 9999;
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
                 }
});
       std::this_thread::sleep_for(std::chrono::seconds(7)); // Sleep for 5 seconds
  }

BOOL hasGhostBeenDrawn = NO; // Biến cờ kiểm soát việc vẽ menu Ghost

using namespace std;
std::string string_format(const std::string fmt, ...) {
    std::vector<char> str(100,'\0');
    va_list ap;
    while (1) {
        va_start(ap, fmt);
        auto n = vsnprintf(str.data(), str.size(), fmt.c_str(), ap);
        va_end(ap);
        if ((n > -1) && (size_t(n) < str.size())) {
            return str.data();
        }
        if (n > -1)
            str.resize( n + 1 );
        else
            str.resize( str.size() * 2);
    }
    return str.data();
}

-(void)text{
mainWindow = [[UIApplication


sharedApplication] keyWindow];
CGRect screenBounds = [[UIScreen mainScreen] bounds];
CGFloat screenWidth = CGRectGetWidth(screenBounds);
CGFloat screenHeight = CGRectGetHeight(screenBounds); // Thêm dòng này để tính screenHeight

// Tạo label và căn lề phía dưới bên trái
UILabel *t = [[UILabel alloc] init];
[t setBackgroundColor:[UIColor clearColor]];
t.layer.cornerRadius = 10;
t.textAlignment = NSTextAlignmentLeft;

NSString *encodedString = @"4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI4paI";
NSData *decodedData = [[NSData alloc] initWithBase64EncodedString:encodedString options:0];
NSString *decodedString = [[NSString alloc] initWithData:decodedData encoding:NSUTF8StringEncoding];

NSLog(@"Decoded string: %@", decodedString);

NSMutableAttributedString *attributedText = [[NSMutableAttributedString alloc] initWithString:decodedString];
NSUInteger length = attributedText.length;
NSArray<UIColor *> *colors = @[[UIColor blackColor]];
for (NSUInteger i = 0; i < length; i++) {
    UIColor *color = colors[i % colors.count];
    [attributedText addAttribute:NSForegroundColorAttributeName value:color range:NSMakeRange(i, 1)];
}

UIFont *font = [UIFont fontWithName:@"AvenirNext-HeavyItalic" size:8];
[attributedText addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, length)];

[t setAttributedText:attributedText];
[t sizeToFit];

// Xác định vị trí căn lề phía dưới bên trái cho label
CGFloat labelX = 8.5;
CGFloat labelY = screenHeight - CGRectGetHeight(t.frame) - 2;
CGRect labelFrame = CGRectMake(labelX, labelY, CGRectGetWidth(t.frame), CGRectGetHeight(t.frame));
[t setFrame:labelFrame];

[mainWindow addSubview:t];


UILabel *myLabel = [[UILabel alloc] initWithFrame:CGRectMake(160, 40, 300, 20)];
myLabel.textColor = [UIColor colorWithRed:0.8 green:0.0 blue:0.4 alpha:1.0];
myLabel.font = [UIFont fontWithName:@"AvenirNext-HeavyItalic" size:17];
myLabel.numberOfLines = 1;
myLabel.text = [NSString stringWithFormat:@""];
myLabel.textAlignment = NSTextAlignmentCenter;
myLabel.shadowColor = [UIColor whiteColor];
myLabel.shadowOffset = CGSizeMake(1.0,1.0); 
myLabel.backgroundColor = [UIColor clearColor];

[mainWindow addSubview:myLabel];

}

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    _device = MTLCreateSystemDefaultDevice();
    _commandQueue = [_device newCommandQueue];

    if (!self.device) abort();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    (void)io;
    
    SetDarkThemeColors();
    io.ConfigWindowsMoveFromTitleBarOnly = true;
    io.IniFilename = NULL;
    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;
    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 7;
    icons_config.OversampleV = 7;
    NSString *FontPath = @"/System/Library/Fonts/Core/AvenirNext.ttc";
    io.Fonts->AddFontFromFileTTF(FontPath.UTF8String, 40.f,NULL,io.Fonts->GetGlyphRangesVietnamese());
    io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);
    ImGui_ImplMetal_Init(_device);

    return self;
}
// Định nghĩa hàm timer trong file .m
- (void)timer:(NSTimeInterval)interval block:(void (^)(void))block {
    // Sử dụng NSTimer để gọi block sau khoảng thời gian
    [NSTimer scheduledTimerWithTimeInterval:interval target:self selector:@selector(executeBlock:) userInfo:[block copy] repeats:NO];
}

- (void)executeBlock:(NSTimer *)timer {
    void (^block)(void) = timer.userInfo;
    if (block) {
        block();  // Thực thi block
    }
}

-(void)ghost{
mainWindow = [[UIApplication sharedApplication] keyWindow];

menuView = [[UIButton alloc]initWithFrame: CGRectMake(305, 265, 58, 54)];
menuView.transform = CGAffineTransformMakeScale(1.0, 1.0);                          
menuView.alpha = 1.0f;
menuView.layer.borderColor = [[UIColor clearColor] CGColor];
menuView.layer.borderWidth = 0.0f;
menuView.layer.cornerRadius = 13;
menuView.layer.borderColor = [[UIColor cyanColor] CGColor];
menuView.layer.borderWidth = 1.5f;
menuView.alpha = 1.0f;
menuView.layer.shadowOpacity = 0;
menuView.layer.shadowColor = [UIColor clearColor].CGColor;
menuView.layer.shadowRadius = 0;
[menuView addTarget:self action:@selector(wasDragged:withEvent:) forControlEvents:UIControlEventTouchDragInside];
[mainWindow addSubview:menuView];


UILabel *tsw = [[UILabel alloc] initWithFrame:CGRectMake(7, 1, 72, 20.8)];
tsw.textColor = [UIColor colorWithRed:255.0/255.0 green:105.0/255.0 blue:180.0/255.0 alpha:1.0];
tsw.font = [UIFont fontWithName:@"CourierNewPS-BoldMT" size:11];
tsw.numberOfLines = 1;
tsw.text = [NSString stringWithFormat:@"Cam Cao"];
tsw.shadowColor = [UIColor clearColor];
tsw.shadowOffset = CGSizeMake(1.1,1.1); 
tsw.backgroundColor = [UIColor clearColor];

[menuView addSubview:tsw];

  UISwitch *sw1 = [[UISwitch alloc] 
initWithFrame: CGRectMake(3.5, 20, 51, 31)];

sw1.layer.borderWidth = 2.5;
sw1.layer.cornerRadius = 5.0;
sw1.layer.borderColor = [UIColor clearColor].CGColor;
sw1.transform = CGAffineTransformMakeScale(1.00, 1.00);
sw1.backgroundColor = [UIColor clearColor];
sw1.layer.cornerRadius = 16;
sw1.thumbTintColor = [UIColor whiteColor];
sw1.onTintColor = [UIColor greenColor];
    [sw1 addTarget:self                action:@selector(switchIsChanged:)                forControlEvents:UIControlEventValueChanged];

    [menuView addSubview:sw1];

hasGhostBeenDrawn = YES; // Đánh dấu menu đã được vẽ

}
- (void)switchIsChanged:(UISwitch *)SW1 {
    
    if ([SW1 isOn]) {
 static dispatch_once_t onceToken;
     dispatch_async(dispatch_get_global_queue(0, 0), ^{
   camcao = true;
});
}
else{
       static dispatch_once_t onceToken;
     dispatch_async(dispatch_get_global_queue(0, 0), ^{
   camcao = false;
     });
}
}
-(void)removeGhost { // Hàm xoá menu Ghost
    if (menuView) {
        [menuView removeFromSuperview];
        menuView = nil;
        hasGhostBeenDrawn = NO; // Đánh dấu menu đã bị xoá
    }
}

+ (void)showChange:(BOOL)open
{
    MenDeal = open;
}

- (MTKView *)mtkView
{
    return (MTKView *)self.view;
}

- (void)loadView{
    CGFloat w = [UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.width;
    CGFloat h = [UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.height;
    self.view = [[MTKView alloc] initWithFrame:CGRectMake(0, 0, w, h)];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.mtkView.device = self.device;
    self.mtkView.delegate = self;
    self.mtkView.clearColor = MTLClearColorMake(0, 0, 0, 0);
    self.mtkView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0];
    self.mtkView.clipsToBounds = YES;
    [self text];
}


#pragma mark - Interaction

- (void)updateIOWithTouchEvent:(UIEvent *)event
{
    UITouch *anyTouch = event.allTouches.anyObject;
    CGPoint touchLocation = [anyTouch locationInView:self.view];
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos = ImVec2(touchLocation.x, touchLocation.y);

    BOOL hasActiveTouch = NO;
    for (UITouch *touch in event.allTouches)
    {
        if (touch.phase != UITouchPhaseEnded && touch.phase != UITouchPhaseCancelled)
        {
            hasActiveTouch = YES;
            break;
        }
    }
    io.MouseDown[0] = hasActiveTouch;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self updateIOWithTouchEvent:event];
}
bool camcao = false;
int CAMCAO(void *instance) {
     if (camcao) {
         return 1;
     }else{
    return 0;
}
}

bool Norecoill = false;
int norecoil(void *instance) {
     if (Norecoill) {
         return 99;
     }else{
    return 1;
}
}




float camxa = 60; 
int CamXa(void *instance) {
    if (camxa > 0.0) {
        return 100.0; 
    } else {
        return 60.0;
    }
}



bool CHUV = true;
int chuV(void *instance) {
     if (CHUV) {
         return 1;
     }else{
    return 0;
}
}
bool NAPDANNHANH = false;
float napdannhanh(void *instance) {
     if (NAPDANNHANH) {
         return 90.0;
     }else{
    return 1.0;
}
}

bool m4a1 = false;
bool xs = false;
bool dame = false;
bool ok = false;
bool tinhyeu = false;
bool luc = false;
bool ngongao = false;
bool aomd = false;
bool macdinh = false;
bool ts = false;
bool namdam = false;
bool ak = false;
bool scar = false;
bool xm8 = false;
bool ump = false;
bool m1014 = false;
bool mp5 = false;
bool an94 = false;
bool nrc = false;
bool db = false;
bool x2 = false;
bool famas = false;
bool m1887 = false;
bool mp40 = false;
bool cc = false; 
bool danthang = false;
bool Aimlock = false;
bool speedx30 = false;
bool rss = false;
bool aimscopev2 = false;
bool tawm = false;
#pragma mark - MTKViewDelegate
#define iPhonePlus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

- (void)drawInMTKView:(MTKView*)view {
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize.x = view.bounds.size.width;
    io.DisplaySize.y = view.bounds.size.height;
    CGFloat framebufferScale = view.window.screen.scale ?: UIScreen.mainScreen.scale;
    if (iPhonePlus) {
        io.DisplayFramebufferScale = ImVec2(2.60, 2.60);
    }else{
        io.DisplayFramebufferScale = ImVec2(framebufferScale, framebufferScale);
    }
    io.DeltaTime = 1 / float(view.preferredFramesPerSecond ?: 120);
    id<MTLCommandBuffer> commandBuffer = [self.commandQueue commandBuffer];

    if (MenDeal == true) {
        [self.view setUserInteractionEnabled:YES];
    } else if (MenDeal == false) {
        [self.view setUserInteractionEnabled:NO];
    }

    MTLRenderPassDescriptor* renderPassDescriptor = view.currentRenderPassDescriptor;
    if (renderPassDescriptor != nil) {
        id<MTLRenderCommandEncoder> renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDescriptor];
        [renderEncoder pushDebugGroup:@"ImGui Jane"];

        ImGui_ImplMetal_NewFrame(renderPassDescriptor);
        ImGui::NewFrame();
        ImGuiStyle& style = ImGui::GetStyle();
        ImFont* font = ImGui::GetFont();
        font->Scale = 18.f / font->FontSize;
        
        CGFloat x = (([UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.width) - 500) / 2;
        CGFloat y = (([UIApplication sharedApplication].windows[0].rootViewController.view.frame.size.height) - 290) / 2;

        ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(500, 320), ImGuiCond_FirstUseEver);

        if (MenDeal) {
                    NSString *bundleIdentifier = [[NSBundle mainBundle] bundleIdentifier];
 std::string Bundle([bundleIdentifier UTF8String]);
 NSString *safari_localizedShortVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSSENCRYPT("CFBundleShortVersionString")];
 std::string Version([safari_localizedShortVersion UTF8String]);
 NSString *safari_displayName = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSSENCRYPT("CFBundleDisplayName")];
 std::string sName([safari_displayName UTF8String]);
                    std::string namedv = [[UIDevice currentDevice] name].UTF8String;
            NSDate *now = [NSDate date];
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"EEEE dd/MM/yyyy"];
            NSString *dateString = [dateFormatter stringFromDate:now];

            UIDevice *device = [UIDevice currentDevice];
            device.batteryMonitoringEnabled = YES;

            float batteryLevel = device.batteryLevel * 100;
            NSString *chargingStatus = @"";
            if (device.batteryState == UIDeviceBatteryStateCharging) {
                chargingStatus = @"- Đang Sạc";
            } else if (device.batteryState == UIDeviceBatteryStateFull) {
                chargingStatus = @"- Đầy Pin";
            } else {
                chargingStatus = @"- Đã Ngắt Sạc";
            }

 

          kern_return_t kr;
          task_info_data_t tinfo;
          mach_msg_type_number_t task_info_count = TASK_INFO_MAX;
          
          kr = task_info(mach_task_self(),
                         TASK_BASIC_INFO,
                         (task_info_t)tinfo,
                         &task_info_count);
          if (kr != KERN_SUCCESS) {
            return;
          }

          task_basic_info_t      basic_info;
          thread_array_t         thread_list;
          mach_msg_type_number_t thread_count;
          
          thread_info_data_t     thinfo;
          mach_msg_type_number_t thread_info_count;

          basic_info = (task_basic_info_t)tinfo;
          
          // Calculate RAM usage
          natural_t used_ram = (basic_info->resident_size) / 1024 / 1024;
          // Calculate available RAM
          natural_t free_ram = ([NSProcessInfo processInfo].physicalMemory) / 1024 / 1024 - used_ram;
          char used_ram_str[100];
          char free_ram_str[100];
          
          ImVec4 used_color = ImVec4(0.5f, 0, 0.5f, 1);
          ImVec4 ram_color = ImVec4(1, 1, 0, 1);

        long num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
        long page_size = sysconf(_SC_PAGESIZE);
        long num_pages = sysconf(_SC_PHYS_PAGES);
        long ram_total = num_pages * page_size;
            ImGui::Begin(ENCRYPT("VDuc - Zalo 0987779460"), &MenDeal);
            if (ImGui::BeginTabBar("FuncTabBar")) {
                if (ImGui::BeginTabItem(ENCRYPT(ICON_FA_HOME"  Home "))) {
                     ImGui::SetWindowFontScale(1.5f);

ImGui::Text("Information");

  ImGui::SetWindowFontScale(1.3f);
 ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 6);
 ImGui::Text(ENCRYPT("                       %s"), sName.c_str());
 ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 6);
 ImGui::Text(ENCRYPT("                       %s"), Bundle.c_str());
 ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 6);
 ImGui::Text(ENCRYPT("                       %s"), Version.c_str());
  ImGui::SetWindowFontScale(1.0f);
                ImGui::TextColored(ImColor(0, 255, 0), "                                                                                                                                                                                                                                                                                                                                                                ");
                ImGui::TextColored(ImColor(255, 255, 255), "Hello ");
                ImGui::SameLine();
                ImGui::TextColored(ImColor(255, 255, 255), "%s", namedv.c_str());

                ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "Trạng Thái: ");
                ImGui::SameLine();
                if (isJailbroken()) {
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Đã Jailbreak !");
                }
                else {
                    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Chưa Jailbreak !");
                }





                ImGui::Separator();
                //thoi gian
                ImGui::TextColored(ImColor(255, 255, 255), "Times: ");
                ImGui::SameLine();
                ImGui::TextColored(ImColor(0, 255, 255), "%s", [dateString UTF8String]);

                ImColor white(255, 255, 255);
                ImGui::TextColored(white, "Battery: ");

                ImColor yellow(255, 255, 0);
                ImGui::SameLine();
                ImGui::TextColored(yellow, " %.0f%%", batteryLevel);

                ImColor green(0, 255, 0);
 
                ImColor red(255, 0, 0);
                ImColor statusTextColor;
                if (device.batteryState == UIDeviceBatteryStateCharging) {
                    statusTextColor = green;
                } else {
                    statusTextColor = red;
                }
                ImGui::SameLine();
                ImGui::TextColored(statusTextColor, "%s", [chargingStatus UTF8String]);

                ImGui::TextColored(white, "Total CPU: ");
                
                ImGui::SameLine();
                ImGui::TextColored(ImColor(0, 255, 0), " %ld bytes", ram_total);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(102, 255, 102), "Core: %ld", num_cpus);







                ImVec4 used_text_color(1, 0, 1, 1);
                ImVec4 used_info_color(1, 1, 0, 1);

                ImGui::TextColored(white, "RAM Usage: ");
                ImGui::SameLine();
                int used_ram_len = snprintf(used_ram_str, sizeof(used_ram_str), "%s: %d MB", "Used", used_ram);

                if (used_ram_len > 0) {
                    ImGui::TextColored(used_text_color, "%s", "Used: ");
                    ImGui::SameLine();
                    ImGui::TextColored(used_info_color, "%d MB", used_ram);
                }
                ImGui::SameLine(); ImGui::TextColored(white, " / ");
                ImGui::SameLine();

                sprintf(free_ram_str, " %d MB", free_ram);
                if (strlen(free_ram_str) > 0) {
                    ImGui::TextColored(ImVec4(0, 1, 0, 1), "Free RAM: ");
                    ImGui::SameLine();
                    ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", free_ram_str);
                }

                ImGui::Separator();
                ImGui::Separator();
                ImGui::EndTabItem();
            }
        

            
                    if (ImGui::BeginTabItem(ENCRYPT(ICON_FA_EYE"ESP"))) {
                    ImGui::BeginGroupPanel("heloo", ImVec2(470, 0));
                    ImGui::Checkbox(" Vẽ ESP", &ESPEnable);
                    ImGui::SliderFloat(" ", &sliderDistanceValue, 0.0f, 300.0f, "Khoảng Cách ESP [ %.3f ]");
                    ImGui::Checkbox("ESP Line ", &ESPLine);
                    
ImGui::Checkbox(" ESP Name  ", &ESPName);

ImGui::Checkbox(" ESP 2D Box  ", &ESPBox);    

ImGui::Checkbox(" Health ", &ESPHealth); 

                    ImGui::Checkbox(" Count ", &ESPCount);


                    ImGui::Checkbox(" 3D Box ", &ESP3DBox);

                ImGui::TextColored(ImColor(18, 255, 0), " Menu Non Jaibreank Make By VDuc.  %.3f ms/frame (%.1f FPS)", 500.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

// id bundle app
//id bundle app
NSString *bundleIdentifier = [[NSBundle mainBundle] bundleIdentifier];

std::string Bundle([bundleIdentifier UTF8String]);


//Phiên bản app
NSString *safari_localizedShortVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSSENCRYPT("CFBundleShortVersionString")];

std::string Version([safari_localizedShortVersion UTF8String]);

//tên của app đang chạy
NSString *safari_displayName = [[NSBundle mainBundle] objectForInfoDictionaryKey:NSSENCRYPT("CFBundleDisplayName")];

std::string sName([safari_displayName UTF8String]);

ImGui::Separator();
ImGui::Separator();

ImGui::TextColored(ImColor(255, 0, 0), ENCRYPT(" Name: %s"), sName.c_str()); // Đỏ
ImGui::TextColored(ImColor(255, 0, 225), ENCRYPT(" Bundle: %s"), Bundle.c_str()); // 
ImGui::TextColored(ImColor(0, 255, 255), ENCRYPT(" Version: %s"), Version.c_str()); // Màu vàng
                    ImGui::EndGroupPanel();
ImGui::EndTabItem();
                }
                
                if (ImGui::BeginTabItem(ENCRYPT(ICON_FA_CROSSHAIRS" AIMBOT"))) {

ImGui::TextColored(ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 1.0f), "Nếu bạn muốn sống lâu hãy sang phần Cn igg Sài hs cu");
                    ImGui::BeginGroupPanel("Functions", ImVec2(470, 0));
                    ImGui::Checkbox("Bật AIMBOT", &aim180);
                    ImGui::Checkbox("Vòng For", &Fov);
                    ImGui::SameLine();
                    ImGui::SliderFloat("", &AimbotFOV, 0.0f, 360.0f, "%.0f");
                    DrawAimbotTab();

ImGui::TextColored(ImVec4(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f), "Đây là phần chức năng offset có thể bật tắt");

ImGui::BeginGroupPanel("Functions", 
ImVec2(470, 0));

ImGui::Checkbox("Đạn Thẳng", &nrc); //ko cần ấn bật nó đã bật
ImGui::Checkbox("Tích V", &CHUV);

ImGui::Checkbox("Nạp Đạn Nhanh", &NAPDANNHANH);

ImGui::SliderFloat("##camxa", &camxa, 60.0f, 150.0f, " Cam Xa %.0f");
                    
ImGui::EndGroupPanel(); 
                  
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem(ENCRYPT(ICON_FA_ANCHOR" IGG Code"))) {
                    ImGui::TextColored(ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 1.0f), "Đây là phần chức năng igg chì bật được chứ không tắt đc");

ImGui::BeginGroupPanel("Functions", ImVec2(470, 0));

ImGui::Checkbox(ENCRYPT("Buff Dame"), &dame);

ImGui::Checkbox(ENCRYPT("HeadShot Cu"), &db);

ImGui::Checkbox(ENCRYPT("Tâm Awm"), &tawm);

ImGui::Checkbox(ENCRYPT("Speed run x8 (ban off)"), &x2);

ImGui::TextColored(ImVec4(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f), "Còn Đây Là Phần Modskin người khác vẫn có thể nhìn thấy bình thường");

ImGui::Checkbox(ENCRYPT("Vỗ tay (M1887 Vũ trụ hủy diệt)"), &m1887);

ImGui::Checkbox(ENCRYPT("Dab (Mp40 Mãng Xà)"), &mp40);

ImGui::Checkbox(ENCRYPT("Cắt Cổ (Scar cá mập đen lv7)"), &scar);

ImGui::Checkbox(ENCRYPT("Huyền Thoại TC (XM8 Lôi Thần LV7"), &xm8);

ImGui::Checkbox(ENCRYPT("Chao (Mp5 Lv7)"), &mp5);

ImGui::TextColored(ImVec4(0.0f / 0.0f, 0.0f / 128.0f, 0.0f / 255.0f, 1.0f), "Còn Đây Là Phần Súng người khác vẫn có thể nhìn thấy bình thường");

ImGui::Checkbox(ENCRYPT("Ak samurai rồng (Ak Rồng Xanh"), &ak);

ImGui::Checkbox(ENCRYPT("M4A1 Hoả Ngục LV7"), &m4a1);

ImGui::Checkbox(ENCRYPT("UMP Boyyah  (UMP Phong Cách LV7"), &ump);

                      
ImGui::EndGroupPanel();                 
                    ImGui::EndTabItem();
                }


                if (ImGui::BeginTabItem(ENCRYPT(ICON_FA_COGS " SETTING"))) {
                    ImGui::BeginGroupPanel("Mua Hack IB Tele : @okiokiokioki123", ImVec2(470, 0));


                    if (ImGui::Button("Fix Login")) {
                        // Ẩn mtkView khi nhấn nút
                        self.mtkView.hidden = YES;
                        MenDeal = NO;  // Thay đổi trạng thái của MenDeal

                        // Đặt timer để phục hồi lại mtkView và cập nhật MenDeal sau một khoảng thời gian
                        [self timer:99 block:^{
                            self.mtkView.hidden = NO;  // Hiển thị lại mtkView
                            MenDeal = YES;  // Cập nhật lại trạng thái MenDeal
                        }];
                    }

                    ImGui::EndGroupPanel();
                    ImGui::EndTabItem();
                }




            
            ImGui::EndTabBar();
            }
            ImGui::End();
            
        }
        if (cc && !hasGhostBeenDrawn) { // Kiểm tra cc và biến cờ
            [self ghost];
        } else if (!cc) {
            [self removeGhost];
        }
        
        DrawEsp();
        iGGCode();
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
        ImGui::Render();
        ImDrawData* draw_data = ImGui::GetDrawData();
        ImGui_ImplMetal_RenderDrawData(draw_data, commandBuffer, renderEncoder);

        [renderEncoder popDebugGroup];
        [renderEncoder endEncoding];
        [commandBuffer presentDrawable:view.currentDrawable];
    }
    [commandBuffer commit];
}
void DrawAimbotTab() {
    static int selectedAimWhen = AimWhen; // Biến lưu giá trị AimWhen đã chọn

    
    ImGui::SliderFloat(" ", &AimDis, 0.0f, 150.0f, "Khoảng Cách AIM [ %.1f ]");
    
    // Combo box cho AimWhen
    const char* aimWhenOptions[] = {"Aim Auto", "Aim Fire", "Aim Scope"};
    ImGui::Combo("Aimbot 180", &selectedAimWhen, aimWhenOptions, IM_ARRAYSIZE(aimWhenOptions));

    // Cập nhật AimWhen từ selectedAimWhen
    AimWhen = selectedAimWhen;
}

void iGGCode() {

if (m4a1) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 907104541; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 907193107;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }

if (mp5) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 909000001; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 909033002;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }

if (xs) { // speed x2

      static dispatch_once_t onceToken;
      dispatch_once(&onceToken, ^{
     JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = {0x100000000, 0x200000000};
        uint64_t search = 4397530849764387586;
        engine.JRScanMemory(range, &search, JR_Search_Type_ULong);   
        vector<void*>results = engine.getAllResults();
        uint64_t modify = 4397530849764387586;
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,
            JR_Search_Type_ULong);
        }
     });
}

if (dame) { 
 
static dispatch_once_t onceToken; 
               dispatch_once(&onceToken, ^{ 
 
JRMemoryEngine engine = JRMemoryEngine(mach_task_self()); 
        AddrRange range = (AddrRange){0x100000000,0x160000000}; 
        float search = 5.5; 
        engine.JRScanMemory(range, &search, JR_Search_Type_Float); 
        float search1 = 1; 
        engine.JRNearBySearch(0x20, &search1, JR_Search_Type_Float); 
        vector<void*>results = engine.getAllResults(); 
        float modify = 9999999; 
        for(int i =0;i<results.size();i++){ 
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float); 
 
        } 
      }); 
                    }


if (ump) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 907101623; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 907193007;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }


if (scar) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 909000018; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 909000068;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }

if (xm8) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 909034012; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 909000085;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }


if (ak) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 907101407; //đây là mã hành động gốc
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 907292407;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }


      if (mp40) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 909000005; //đây là mã hành động gốc dab
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 909000075;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }

      if (m1887) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x200000000};
        uint32_t search = 909000004; //đây là mã hành động gốc vỗ tay
        engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
        vector<void*>results = engine.getAllResults();
       uint32_t modify = 909035007;//còn đây là mã mod
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_UInt);
                 }
    });
    }

    // if (Aimlock) {
    //     static dispatch_once_t onceToken;
    //     dispatch_once(&onceToken, ^{
    //       JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
    //       AddrRange range = (AddrRange){0x100000000, 0x160000000};
    //       float search = 0.15;
    //       engine.JRScanMemory(range, &search, JR_Search_Type_Float);
    //       float search1 = 1.5;
    //       engine.JRNearBySearch(0x60, &search1, JR_Search_Type_Float);
    //       float search2 = 1.5;
    //       engine.JRScanMemory(range, &search2, JR_Search_Type_Float);
    //       vector<void *> results = engine.getAllResults();
    //       float modify = 9999999;
    //       for (int i = 0; i < results.size(); i++) {
    //           engine.JRWriteMemory((unsigned long long)(results[i]), &modify, JR_Search_Type_Float);
    //       }
    //     });
    // }
    if (aim180) {
        static dispatch_once_t onceToken;
       dispatch_once(&onceToken, ^{
    std::thread aim180Thread(aim180Function);
    aim180Thread.detach(); // Detach the thread to run independently
    std::thread aimscopeThread(aimscopeFunction);
    aimscopeThread.detach(); // Detach the thread to run independently
    std::thread aimawmThread(aimawmFunction);
    aimawmThread.detach(); // Detach the thread to run independently
    std::thread LockfireThread(LockfireFunction);
    LockfireThread.detach(); // Detach the thread to run independently
});
    }
    
    
if (x2) { // speed x2

      static dispatch_once_t onceToken;
      dispatch_once(&onceToken, ^{
     JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = {0x100000000, 0x200000000};
        uint64_t search = 4397530849764387586;
        engine.JRScanMemory(range, &search, JR_Search_Type_ULong);   
        vector<void*>results = engine.getAllResults();
        uint64_t modify = 4366458311853765201;
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,
            JR_Search_Type_ULong);
        }
     });
}

    

    if (db) {

static dispatch_once_t onceToken;
               dispatch_once(&onceToken, ^{

JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
        AddrRange range = (AddrRange){0x100000000,0x160000000};
        uint32_t search = 2183231598;
        engine.JRScanMemory(range, &search, JR_Search_Type_Float);
        uint32_t search1 = 96688289;
engine.JRNearBySearch(0x10,&search1,JR_Search_Type_Float);
        uint32_t search2 = 96688289;
        engine.JRScanMemory(range, &search2, JR_Search_Type_Float);
        vector<void*>results = engine.getAllResults();
        uint32_t modify = 2018908708;
        for(int i =0;i<results.size();i++){
        engine.JRWriteMemory((unsigned long long)(results[i]),&modify,JR_Search_Type_Float);
                 }
    });
    }
if (tawm) { // tâm awm

        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
        JRMemoryEngine engine(mach_task_self());
        AddrRange range = {0x100000000, 0x160000000};
        uint64_t searchNumber = 4603687625386098688ULL;
        engine.JRScanMemory(range, &searchNumber, JR_Search_Type_ULong);
        std::vector<void*> results = engine.getAllResults();
        float newValueFloat = 0.01f;
        int32_t newValueInt = 0;
        for (void* addr : results) {
        uint64_t addr1 = reinterpret_cast<uint64_t>(addr);
        uint64_t dizhi0 = addr1 + 36;
        uint64_t dizhi1 = addr1 + 40;
        uint64_t dizhi2 = addr1 - 308;
        engine.JRWriteMemory(dizhi0, &newValueFloat, JR_Search_Type_Float);
        engine.JRWriteMemory(dizhi1, &newValueFloat, JR_Search_Type_Float);
        engine.JRWriteMemory(dizhi2, &newValueInt, JR_Search_Type_SInt);
            }
                });
            }
            
}

    // if (aimscopev2) {
    //     static dispatch_once_t onceToken;
    //     dispatch_once(&onceToken, ^{
    //       JRMemoryEngine engine = JRMemoryEngine(mach_task_self());
    //       AddrRange range = (AddrRange){0x130100048, 0x200000000};
    //       uint32_t search = 1075000115;
    //       engine.JRScanMemory(range, &search, JR_Search_Type_UInt);
    //       vector<void *> results = engine.getAllResults();
    //       uint32_t modify = -5;
    //       for (int i = 0; i < results.size(); i++) {
    //           engine.JRWriteMemory((unsigned long long)(results[i]), &modify, JR_Search_Type_UInt);
    //       }
    //     });
    // }


void hooking() {
    void* address[] = {  
        (void*)getRealOffset(ENCRYPTOFFSET("0x103E526F0")), 
        (void*)getRealOffset(ENCRYPTOFFSET("0x10529A408")), 
        (void*)getRealOffset(ENCRYPTOFFSET("0x103851DC4")),
        // (void*)getRealOffset(ENCRYPTOFFSET("0x1040D1ABC")), 
        (void*)getRealOffset(ENCRYPTOFFSET("0x1051D1F94")),
        (void*)getRealOffset(ENCRYPTOFFSET("0x1040D6610")),
        (void*)getRealOffset(ENCRYPTOFFSET("0x1052620FC"))  
    };
    void* function[] = {
        (void*)CamXa,
        (void*)Update,
        (void*)chuV,
        // (void*)noaim1,  
        (void*)norecoil,  
        (void*)napdannhanh,
        (void*)OnDestroy
    };
    hook(address, function, 6);

    Local = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x105258C80"));                           
    Team = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x10526D118"));                               
    get_CurHP = (int (*)(void *))getRealOffset(ENCRYPTOFFSET("0x1052A8A30"));                            
    get_MaxHP = (int(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1052A8AD8"));                           
    get_position = (Vector3(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105F3D46C"));                   
    WorldToViewpoint = (Vector3(*)(void *, Vector3, int))getRealOffset(ENCRYPTOFFSET("0x105EF6394"));   
    get_main = (void *(*)())getRealOffset(ENCRYPTOFFSET("0x105EF6D08"));                                
    get_transform = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105EF8D78"));    
}

void *hack_thread(void *) {
    sleep(5);
    hooking();
    pthread_exit(nullptr);
    return nullptr;
}

void __attribute__((constructor)) initialize() {
    pthread_t hacks;
    pthread_create(&hacks, NULL, hack_thread, NULL);
}
- (void)mtkView:(MTKView*)view drawableSizeWillChange:(CGSize)size{}

@end
