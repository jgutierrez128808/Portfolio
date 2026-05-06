# Project: Personal Portfolio & Music Showcase

## Why this site exists

This site is being built as proof of work for two parallel tracks: **graduate program applications** (Fall 2027 — CCRMA at Stanford and CalArts as top choices, plus SFCM's Technology and Applied Composition program as a strong local fit) and **hardware/embedded engineering job applications**. It needs to do both jobs at once: read as a research-oriented portfolio for admissions readers (who care about originality, focus, and the ability to articulate a design question), and as a technical portfolio for hiring managers (who care about real, working hardware with documentation, code, audio, and measurements).

This frames everything else. The aesthetic isn't just decoration — it's there to signal taste and a real point of view (which admissions reviewers care about) while echoing the lab-equipment / synth-DIY visual world (which the hardware audience recognizes). But it has to *contain* substantive content, not just decorate around it. Vibe at first glance, serious portfolio on second click.

## Background (mine)

- Electrical Engineering graduate, UC Santa Cruz
- Currently a Validation Engineer at PSC Biotech (pharma/biotech consulting). Sharpens documentation discipline; not where the creative ambition lives.
- Undergraduate capstone: a fully discrete analog synthesizer built from Moritz Klein and René Schmitz schematics, with a Daisy Seed microcontroller handling envelope generator and LFO duties. Foundation for everything since.
- Musician since age 8 (guitar primarily; also piano, bass, synthesizer). Decade of band experience. Several projects released on streaming. Active Ableton + Apollo Twin production. Tascam Portastudio four-track work.

The narrative thread: I'm an EE who plays and ships music, building toward **original circuit and instrument design** rather than cloning existing schematics. Lead with original work; reverse-engineering and study notes go in a secondary section.

## What needs to be featured

**Original instrument design (lead with these — most important for admissions):**
- The capstone analog synthesizer (needs proper writeup: schematics, audio, what I'd do differently)
- Lap steel synthesizer — futuristic take on the lap steel form factor, dedicated oscillator per string, SoftPot membrane potentiometers for slide position, piezo contact mics for pluck/velocity. Single-voice prototype phase.
- Motor-based drone synth — N20 gear motors as sound sources, piezo contact mics, TL072 preamp, LM358-driven 2N2222 emitter follower for closed-loop motor speed control. Verified in CircuitJS. Lineage from Telharmonium / Hammond tonewheel organs / Gamechanger Motor Synth.

**Music:**
- Released tracks via Spotify embeds (folk and grunge, almost always with synths in the mix)
- Potentially a full album's worth of material

**Secondary technical work (notes / lab section):**
- Eurorack exploration (briefcase DIY enclosure, bus board, PSU selection)
- Home electronics lab inventory (TL072, LM13700, Thonkiconn jacks, etc.)
- Raspberry Pi Zero 2W as Pi-hole DNS server (privacy-conscious DIY infrastructure)

**Hard requirement: audio and video on every instrument page.** Silent GitHub repos don't sell music technology work. Plan for embedded audio clips and short video demos on every project page from the start.

## Who's building it

I'm new to web development. This is my first real site, and I'm coding it myself rather than using a site builder because I want to actually learn and because custom code gives more aesthetic control, not less. When helping me, lean toward **teaching** rather than just shipping code: explain what's happening, why a particular approach is idiomatic, and flag when I'm doing something that'll bite me later. Don't over-explain trivial syntax once I've shown I understand it.

If I'm about to do something a more experienced dev wouldn't, say so.

## Tech stack

- **Framework**: Astro (static site)
- **Styling**: Tailwind CSS (planned — confirm before assuming it's installed)
- **Hosting**: Cloudflare Pages or Vercel (deciding)
- **Music**: Spotify embeds (no self-hosted audio for released tracks)
- **Video**: TBD — likely Cloudflare Stream, Vimeo, or self-hosted MP4s for short demos
- **Domain**: Cloudflare Registrar or Namecheap (TBD)
- **Dev environment**: VS Code, Node.js, Git, GitHub
- **Animation**: GSAP and/or Framer Motion when motion is needed

## Workflow

Local editing in VS Code → commit → push to GitHub → automatic redeploy on the host. Keep this loop in mind when suggesting changes; prefer solutions that work with this flow rather than against it.

## Visual direction

The aesthetic is **retro handheld / early-console phosphor green** — drawing from Game Boy DMG, Nintendo DS, and PlayStation 1 era visual language, plus oscilloscope and lab-equipment energy that ties into the synth-building work. The frame: the site should feel like a piece of warm, glowing electronic equipment.

Specific qualities:
- **Color**: phosphor green on near-black, with a slight olive/warm cast (Game Boy DMG, not harsh terminal green). Narrow palette — green ramp + dark backgrounds + maybe one accent.
- **Typography**: pixel/bitmap fonts. Candidates worth trying: VT323, Press Start 2P (sparingly, for headlines), PixelMplus, or similar. Monospace fallback in the meantime.
- **Texture**: scanlines, subtle CRT vignette, occasional flicker. Dithering patterns are welcome where they fit (PS1/Game Boy used dithering as a rendering technique — it's part of the vocabulary).
- **UI metaphors**: boot screens, attract modes, menu selection, status bars, terminal prompts. Navigation should feel like operating a device, not browsing a website.
- **Restraint at the surface, substance underneath**: the home page and navigation are visually-driven and minimal. Project pages can be denser and more substantive — schematics, audio, video, design notes, what-I'd-do-differently sections. The aesthetic frames the content; it doesn't replace it.

The user shouldn't feel like they're on a generic SaaS landing page. Reach for distinctive details over default patterns.

## Animation philosophy

Modern animation, retro visuals. Use GSAP (or Framer Motion where it fits Astro's island model) for things like:
- Idle Lissajous-figure drift on the oscilloscope
- CRT power-on/power-off transitions between sections
- Typewriter text reveals on key headlines
- Cursor blinks, scanline sweeps, subtle phosphor flicker
- Sprite-style or dither-style transitions

Restraint is key. A few well-timed, deliberate motions hit harder than constant movement. The goal is "this thing is alive and on" — not "this thing is showing off."

## Site structure (planned)

- **Home page**: vibe-establishing doorway. Name, role, an idle oscilloscope visual, three clear paths into the site (Instruments / Music / Notes). No long copy. Single-screen-ish.
- **Instruments page**: the lead section for admissions and hardware audiences. Original design work — capstone, lap steel synth, motor drone synth — each with its own detail page. Treated like manual/catalog entries: schematics as design elements, technical specs styled into the layout, embedded audio + video demos, design-question writeups.
- **Music page**: track listings as liner-notes-style typography, Spotify embeds, and an audio-reactive Lissajous oscilloscope (see below). Quieter, more textural.
- **Notes (or Lab/Bench) page**: secondary technical work — Eurorack exploration, Pi-hole, study notes, reverse-engineering. Keeps the original work front-and-center on Instruments and gives the rest a home.

## The Lissajous oscilloscope

Concept: the music page features a digital oscilloscope display that, ideally, draws Lissajous figures in response to the playing track. This is a defining visual element for the site and ties directly to the synth-builder identity (real scopes are a daily-driver tool in synth design).

**Phase 1 (start here, minimize complexity)**: pre-rendered or procedurally-animated SVG that *looks* like an oscilloscope drawing Lissajous figures. Idle drift, subtle phosphor afterglow, looks alive but isn't actually responding to audio. Built with GSAP for the animation.

**Phase 2 (only after Phase 1 is solid)**: real audio reactivity. This will require Web Audio API + analyser nodes. Spotify's embed doesn't expose audio data to the page (licensing limitation), so the real version would need self-hosted preview clips or an alternative source for the data. Defer this decision until Phase 1 is shipped and the rest of the site is in good shape.

## Design principles

- Typography choices and hierarchy do most of the heavy lifting
- Restraint with color (phosphor green plus near-black plus maybe one accent — not a rainbow)
- Generous whitespace where it fits the aesthetic; deliberate density where it doesn't
- Polished details — transitions, hover states, spacing rhythm
- Distinctive over generic, always
- Substance over performance — the aesthetic exists to frame real work, not hide a lack of it

Inspiration sources: Awwwards, Siteinspire, godly.website, Are.na — but filtered through the retro-handheld lens. Reference points like Teenage Engineering, Critter & Guitari, Elektron's UI, and old game-console boot screens are closer to the mark for this project than typical web-design moodboards.

## Libraries I'm open to using

Tailwind CSS, Framer Motion, GSAP, shadcn/ui, Radix. Suggest these where they fit; don't reach for heavy dependencies for things vanilla CSS handles fine.

## Current status

Early stage. Working through fundamentals (HTML/CSS via MDN, then the official Astro tutorial) alongside building. Home page is the first concrete target.

## How to help me well

- Show me the change, then explain the reasoning briefly
- If there's a more idiomatic Astro pattern than what I wrote, say so
- Don't generate huge amounts of code at once — I want to actually understand what's in my repo
- When I ask for something visual, push back if the request would produce a generic result; suggest a more distinctive direction in line with the aesthetic above
- Remember the audiences: this site has to read well to grad admissions reviewers and hardware hiring managers, not just to me. If I'm about to make a choice that would undermine either, flag it.
- Update this file when we make decisions worth remembering (stack changes, conventions, structural choices, new visual decisions)
